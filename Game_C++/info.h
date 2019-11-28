using namespace std;

int MAP[5][10][10] =
{
	{
		{1, 1, 1, 1, 4, 4, 4, 4, 4, 4},
		{1, 3, 0, 1, 1, 4, 4, 4, 4, 4},
		{1, 3, 0, 0, 1, 4, 4, 4, 4 ,4},
		{1, 3, 0, 2, 1, 4, 4, 4, 4, 4},
		{1, 1, 2, 0, 1, 1, 1, 4, 4, 4},
		{4, 1, 0, 2, 0, 0, 1, 4, 4, 4},
		{4, 1, 0, 0, 0, 0, 1, 4, 4, 4},
		{4, 1, 0, 0, 1, 1, 1, 4, 4, 4},
		{4, 1, 1, 1, 1, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 1, 0, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 3, 3, 1, 4, 4, 4},
		{4, 4, 1, 2, 2, 2, 1, 1, 4, 4},
		{4, 4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4, 4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 3, 0, 0, 0, 0, 0, 1, 4},
		{4, 1, 0, 3, 2, 2, 2, 0, 1, 4},
		{4, 1, 3, 0, 0, 0, 0, 0, 1, 4},
		{4, 1, 1, 1, 1, 1, 0, 0, 1, 4},
		{4, 4, 4, 4, 4, 1, 1, 1, 1, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 4, 1, 0, 0, 0, 0, 0, 1, 4},
		{4, 4, 1, 0, 3, 2, 3, 0, 1, 4},
		{4, 4, 1, 0, 2, 3, 2, 0, 1, 4},
		{4, 4, 1, 0, 3, 2, 3, 0, 1, 4},
		{4, 4, 1, 0, 2, 3, 2, 0, 1, 4},
		{4, 4, 1, 0, 0, 0, 0, 0, 1, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 4, 4, 4, 4, 4},
		{4, 1, 0, 0, 1, 1, 1, 1, 4, 4},
		{4, 1, 0, 0, 0, 0, 0, 1, 1, 4},
		{1, 1, 0, 1, 1, 0, 0, 0, 1, 4},
		{1, 3, 0, 3, 1, 0, 0, 2, 1, 1},
		{1, 0, 0, 0, 1, 0, 2, 2, 0, 1},
		{1, 0, 0, 3, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	}
};

int INFO[5][3] =
{
	//(box Number, init character row, init character col)
	{ 3, 2, 2 },
	{ 3, 7, 3 },
	{ 3, 5, 7 },
	{ 6, 7, 5 },
	{ 3, 5, 6 }
};
