void UFunczoneobst::objectAnalysis(double angleRelation, double* lsqlines, double* objects)
{ // objects contain the confidence in the 4 different objects.
	if (shortestLength >= 12 && shortestLength <= 17)
	{
		objects[0] = objects[0] + 1;
		objects[3] = objects[3] + 1;
	}

	if (shortestLength >= 17 && shortestLength <= 22)
	{
		objects[2] = objects[2] + 1;
	}
	else if (longestLength >= 36 && longestLength <= 40)
	{
		objects[0] = objects[0] + 1;
		objects[2] = objects[2] + 1;
	}
	else if (longestLength >= 28 && longestLength <= 31)
	{
		objects[1] = objects[1] + 1;
		objects[3] = objects[3] + 1;
	}
	else if (longestLength >= 30 && longestLength <= 36)
	{
		objects[3] = objects[3] + 1;
	}
	else if (longestLength >= 38 && longestLength <= 42)
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
