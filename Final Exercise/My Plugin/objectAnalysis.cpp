void UFunczoneobst::objectAnalysis(double angleRelation, double* lsqlines, int* objects)
{ // objects contain the confidence in the 4 different objects.
	if (lsqlines[5] >= 0.12 && lsqlines[5] <= 0.17)
	{
		objects[0] = objects[0] + 1;
		objects[3] = objects[3] + 1;
	}

	if (lsqlines[5] >= 0.17 && lsqlines[5] <= 0.22)
	{
		objects[2] = objects[2] + 1;
	}
	else if (lsqlines[4] >= 0.36 && lsqlines[4] <= 0.40)
	{
		objects[0] = objects[0] + 1;
		objects[2] = objects[2] + 1;
	}
	else if (lsqlines[4] >= 0.28 && lsqlines[4] <= 0.31)
	{
		objects[1] = objects[1] + 1;
		objects[3] = objects[3] + 1;
	}
	else if (lsqlines[4] >= 0.30 && lsqlines[4] <= 0.36)
	{
		objects[3] = objects[3] + 1;
	}
	else if (lsqlines[4] >= 0.38 && lsqlines[4] <= 0.42)
	{
		objects[2] = objects[2] + 1;
	}
	if (angleRelation < 1)
	{
		objects[2] = objects[2] + 1;
		objects[3] = objects[3] + 1;
	}
	else
	{
		objects[0] = objects[0] + 1;
		objects[1] = objects[1] + 1;
	}


}