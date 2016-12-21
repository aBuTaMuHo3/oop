// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

double CalculateMinor(int pos1, int pos2, double matrix[3][3])
{
	double minorMatrix[2][2];
	int minorX, minorY;
	minorX = 0;
	minorY = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << matrix[i][j] << endl;
			if (i != pos1 && j != pos2)
			{
				minorMatrix[minorX][minorY] = matrix[i][j];
				cout << matrix[i][j] << endl;
				minorY++;
				if (minorY >= 2)
				{
					minorX++;
					minorY = 0;
				}
			}
		}
		
	}

	cout << minorMatrix[0][0] << " minor11" << endl;

	return minorMatrix[0][0] * minorMatrix[1][1] - minorMatrix[0][1] * minorMatrix[1][0];
}

int main(int argc, char * argv[])
{
	ifstream matrixFile;
	/*if (argc != 2)
	{
		cout << "Invalid arguments count\n" << "Usage: invert.exe <input file>\n";
		return 1;
	}
	else
	{
		matrixFile = fopen(argv[1], "r");
		if (matrixFile == NULL)
		{
			cout << "There is no flie: " << argv[1]<< endl;
			return 1;
		}
	}*/
	//matrixFile.open("mtrx.txt");
	string inFileName = "mtrx.txt";
	matrixFile.open(inFileName, fstream::in);
	double matrix[3][3];
	double minorMatrix[3][3];
	double determinant = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixFile >> (matrix[i][j]);
		}
	}
	determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
	cout<<"\n";
	double alpha2 = CalculateMinor(0, 0, matrix);
	cout << alpha2 << endl;
	if (determinant != 0)
	{
		
	}
	else
	{
		cout << "Determinant = 0\n Impossible to invert matrix" << endl;
		return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << determinant << endl;
}
