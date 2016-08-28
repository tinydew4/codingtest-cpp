#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <tuple>
#include <vector>
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void trace(int Map[10][10], int size)
{
	for (int i = 0, a = size; a-- > 0; i++) {
		for (int j = 0, b = size; b-- > 0; j++) {
			std::cout << Map[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T, int V>
void FillMap(T AMap[10][10], T AValue)
{
	for (int a = V; a-- > 0; std::fill_n(AMap[a], V, AValue));
}
class Map
{
private:
	int FLength;
	int FMudMap[10][10];
	int FCostMap[10][10];

public:
	Map(void)
		: FLength(0)
	{
		FillMap<int, 10>(FMudMap, 0);
		FillMap<int, 10>(FCostMap, 0);
	}
	void Input(void)
	{
		std::string input;
		std::cin >> FLength;
		for (int i = FLength; i-- > 0; ) {
			std::cin >> input;
			for (int j = 0, b = FLength; b-- > 0; j++) {
				FMudMap[i][j] = input[j] - '0';
			}
		}
        FCostMap[FLength - 1][FLength - 1] = 100;
	}
	class MapMove
	{
	private:
		bool FStepMap[10][10];
		class IntValue {
		private:
			int FValue;
		public:
			int& operator=(const int &AValue) {
				return (FValue = AValue);
			}
			operator int() const {
				return FValue;
			}
		};
	public:
		MapMove(void)
		{
			FillMap<bool, 10>(FStepMap, false);
			Col = 0;
			Row = 0;
			Step();
		}
		IntValue Col;
		IntValue Row;
        IntValue Length;
		void Step(void)
		{
			FStepMap[Col][Row] = true;
		}
		bool Move(int AColStep, int ARowStep, bool ADoMove = true)
		{
			int iCol = Col;
			int iRow = Row;
			if (AColStep) {
				iCol += AColStep;
				if (0 > iCol || iCol >= Length || FStepMap[iCol][Row]) {
					return false;
				}
			}
			if (ARowStep) {
				iRow += ARowStep;
				if (0 > iRow || iRow >= Length || FStepMap[Col][iRow]) {
					return false;
				}
			}
			if (ADoMove && (iCol != Col || iRow != Row)) {
				Col = iCol;
				Row = iRow;
				Step();
			}
			return true;
		}
	};
	bool EvaluateCost(int ACol, int ARow, int ACost)
	{
		ACost += FMudMap[ACol][ARow];
		int iCost = FCostMap[ACol][ARow];
		if (iCost == 0 || iCost > ACost) {
			FCostMap[ACol][ARow] = ACost;
			return true;
		}
		return false;
	}
	void Evaluate(MapMove AMove = MapMove())
	{
		if (FCostMap[AMove.Col][AMove.Row] >= 100) {
            return;
        }
		AMove.Length = FLength;
		int iStep[4][2] = {
			{0, -1},
			{1, 0},
			{0, 1},
			{-1, 0},
		};
        bool can_move[] = {false, false, false, false};
		MapMove sub_move[] = {AMove, AMove, AMove, AMove};

		for (int i = 0, a = 4; a-- > 0; i++) {
			if ((can_move[i] = sub_move[i].Move(iStep[i][0], iStep[i][1]))
				&& (FCostMap[AMove.Col][AMove.Row] < 100 || FCostMap[sub_move[i].Col][sub_move[i].Row] <= 0)) {
				can_move[i] = EvaluateCost(sub_move[i].Col, sub_move[i].Row, FCostMap[AMove.Col][AMove.Row]);
			}
		}
		for (int i = 0, a = 4; a-- > 0; i++) {
			if (can_move[i]) {
				Evaluate(sub_move[i]);
			}
		}
	}
	int GetCost(void) const
	{
		int iResult = FCostMap[FLength - 1][FLength - 1];
		return (iResult <= 100? iResult: 100);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Map mudmap;
	mudmap.Input();
	mudmap.Evaluate();
	std::cout << mudmap.GetCost() << std::endl;
	return 0;
}
