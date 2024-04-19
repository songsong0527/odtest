
const int Batch = 8;

void CalcGrad(Tensor t, vector<CVSample> samples, RollAvg& ravg)
{
	vector<float> data, grad, myid;
	float avg = 0;
	t.get(data);
	grad.resize(data.size());

	int N = t.getdim()[0];  //batch
	int C = t.getdim()[1];	//neuron
	int H = t.getdim()[2];	//height
	int W = t.getdim()[3];	//weight

	for (int b = 0; b < N; b++)
	{
		float* dptr = data.data() + b * C * H * W;
		float* gptr = grad.data() + b * C * H * W;

		//
		for (int i = 0; i < H * W * 4; i++)
		{
			gptr[i] = (0.0f - dptr[i]) * 0.01f;
		}

		CVSample s = samples[b];
		for (CVAnno anno : s.annos)
		{
			Pointf pnt = anno.box().center();

			int id = anno.classid;

			int px = static_cast<int>(pnt.x * W);
			int py = static_cast<int>(pnt.y * H);

			int idx = py * W + px;

			gptr[idx] = (1.0f - dptr[idx]) * 0.1f;

			switch (id)
			{
			case 0:
				gptr[idx + 18 * 32] = (1.0f - dptr[idx + 18 * 32]);
				break;
			case 1:
				gptr[idx + 18 * 32 * 2] = (1.0f - dptr[idx + 18 * 32 * 2]);
				break;
			case 2:
				gptr[idx + 18 * 32 * 3] = (1.0f - dptr[idx + 18 * 32 * 3]);
				break;
			}
			avg += 1.0f - dptr[idx];
		}
	}
	ravg += avg;


	t.setgrad(grad);
}

void PumpLightDetect()
{
	//Image img = ReadImage("E:/DataSet/PumpLight/train/1000009-E2-142.jpg");
	//DrawRect(img, Rectf(0.4f, 0.5f, 0.1f, 0.1f), PCOLOR(255, 255));
	//Print(img);

	CVSampleLoader cvsl;
	cvsl.LoadFromDarknet("E:\\QGY\\DataSet\\PumpLight\\train");
	Tensor x(Batch, 3, 576, 1024);
	Tensor y = Relu(Conv(x, 8, 3, 2, 1)); // 8, 8, 288, 512
	y = YoloTinyV4Block(y, 16); //8, 24, 144, 256
	y = YoloTinyV4Block(y, 32); //8, 48, 72, 128
	y = YoloTinyV4Block(y, 64); //8, 92, 36, 64
	y = YoloTinyV4Block(y, 128); //8, 192, 18, 32
	y = ResnetBlockA(y);//8, 192, 18, 32
	y = ResnetBlockA(y);//8, 192, 18, 32
	y = Sigmoid(Conv(y, 1 + 3, 3, 1, 1));//8, 1, 18, 32
	auto graph = SetUp(x, y);
	SaveGraphONNX(graph, "test.onnx");

	Optimizer opt;
	opt.EnableLearnRate(true, 0.001f);
	opt.EnableMomentum(true, 0.9f);

	RollAvg ravg;
	int i = 0;
	while (true)
	{
		vector<CVSample> samples = cvsl.GetBatchSample(Batch);
		SetTensorByCVSamples(x, samples);

		graph.Forward();
		CalcGrad(y, samples, ravg);

		graph.Backward();
		opt.Update(graph.GetWeights());

		i++;
		printf("%d loss:%f \r", i, (float)ravg);
		if (i > 0 && i % 1000) {
			SaveGraph(graph, "E:\\QGY\\model.ng");
		}
	}
	SaveGraph(graph, "E:\\QGY\\model.ng");
}

struct MyPoint
{
	float x;
	float y;
};

void Test() {
	NeuroGraph testgraph = LoadGraph("D:\\model.ng");
	Tensor testx = testgraph.GetInputTensor();
	Tensor testy = testgraph.GetOutputTensor();
	while (true)
	{
		string path;
		std::cout << "输入图片路径" << std::endl;
		std::cin >> path;
		//图片转张量
		Image image = ReadImage(path, 3);
		/*Image image = ReadImage(s.path, 3);*/
		Tensor t = TensorFromImage(image, 3, 576, 1024, gsp::NGPU);
		//把数据复制到输入张量里面
		testx.refer(t);
		testgraph.Forward();
		//获取预测值
		vector<float> Ydata;
		testy.get(Ydata);

		//for (float& Ydatai : Ydata) {
		//	if (Ydatai>0.5)
		//	{

		//	}
		//}

		vector<MyPoint> points;
		vector<float> Singlelables;
		vector<int> Alllables;

		for (int i = 0; i < Ydata.size(); i++)
		{
			MyPoint point;
			if (Ydata[i] > 0.5f && i < 18 * 32)
			{
				Singlelables.clear();
				point.x = (i % 32) / 32.0f;
				point.y = (i / 32) / 18.0f;
				points.push_back(point);
				for (int j = 0; j < 3; j++)
				{
					Singlelables.push_back(Ydata[j * 18 * 32 + i]);
				}
				// 计算最大值的索引
				auto max_iter = max_element(Singlelables.begin(), Singlelables.end());
				if (max_iter != Singlelables.end()) {
					int max_index = std::distance(Singlelables.begin(), max_iter);//获得单个物品的lable
					Alllables.push_back(max_index);
				}
			}
		}


		Image img = ReadImage(path);
		for (int i = 0; i < points.size(); i++)
		{
			DrawRect(img, Rectf(points[i].x, points[i].y, 0.1f, 0.1f), PCOLOR(255, 255));
			wstring	status;
			switch (Alllables[i])
			{
			case 0:
				status.assign(L"熄");
				break;
			case 1:
				status.assign(L"亮");
				break;
			case 2:
				status.assign(L"不是灯");
				break;
			default:
				break;
			}

			PutText(img, status, Pointf(points[i].x, points[i].y));
		}



		//for (MyPoint& pointi : points) {
		//	DrawRect(img, Rectf(pointi.x, pointi.y, 0.1f, 0.1f), PCOLOR(255, 255));
		//}

		Print(img);

	}
}