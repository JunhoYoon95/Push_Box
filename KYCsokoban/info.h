using namespace std;

int MAP[5][8][8] =
{
	{
		{4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 0, 0, 0, 0, 1, 4},
		{4, 1, 0, 0, 0, 0, 1, 4},
		{4, 1, 3, 2, 0, 0, 1, 4},
		{4, 1, 0, 0, 0, 0, 1, 4},
		{4, 1, 1, 1, 1, 1, 1, 4},
		{4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 0, 0, 0, 0, 1, 4},
		{4, 1, 0, 0, 0, 0, 1, 4},
		{4, 1, 0, 3, 3, 3, 1, 4},
		{4, 1, 0, 2, 2, 2, 1, 4},
		{4, 1, 0, 0, 0, 0, 1, 4},
		{4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 0, 0, 0, 0, 0, 4},
		{4, 1, 0, 0, 0, 0, 0, 4},
		{4, 1, 3, 0, 0, 0, 0, 4},
		{4, 1, 3, 2, 2, 2, 0, 4},
		{4, 1, 3, 0, 0, 0, 0, 4},
		{4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4},
		{4, 0, 0, 0, 0, 0, 0, 4},
		{4, 0, 3, 2, 3, 0, 0, 4},
		{4, 0, 2, 3, 2, 0, 0, 4},
		{4, 0, 3, 2, 3, 0, 0, 4},
		{4, 0, 2, 3, 2, 0, 0, 4},
		{4, 0, 0, 0, 0, 0, 0, 4},
		{4, 4, 4, 4, 4, 4, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 0, 0, 0, 0, 0, 4},
		{4, 1, 0, 0, 0, 2, 0, 4},
		{4, 1, 0, 0, 1, 2, 0, 4},
		{4, 3, 0, 3, 1, 0, 0, 4},
		{4, 0, 0, 0, 1, 0, 0, 4},
		{4, 4, 4, 4, 4, 4, 4, 4}
	}
};

int INFO[5][3] =
{
	//(box Number, init character row, init character col)
	{ 1, 4, 4},
	{ 3, 6, 4},
	{ 3, 6, 4},
	{ 6, 6, 4},
	{ 2, 6, 5}
};