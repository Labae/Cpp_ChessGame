#include "ChessGraphics.h"

ChessGraphics::ChessGraphics()
{
}

ChessGraphics::~ChessGraphics()
{
}

bool ChessGraphics::Initialize()
{
	return true;
}

/// TODO : 2중 배열로 해서 이것저것 수정해야 할듯.
bool ChessGraphics::Render(ChessBoard* board, Queue<Vector2<int>>* inputLog, ChessPieces* selectedPiece, const int& team, const bool& gameover)
{
	using namespace std;

	system("cls");

	char* szBottom[] = { "A ", "B ", "C ", "D ", "E ", "F ", "G ", "H " };
	char* szLeft[] = { "8","7","6","5","4","3","2","1" };
	ChessPieces* piece = 0;

	// 커서 좌표.
	unsigned int cursorPosX = inputLog->GetLastElement().GetX();
	unsigned int cursorPosY = inputLog->GetLastElement().GetY();
	unsigned int prevCursorPosX = inputLog->GetFirstElement().GetX();
	unsigned int prevCursorPosY = inputLog->GetFirstElement().GetY();

	// 렌더링용 커서 좌표.
	unsigned int renderCursorX = inputLog->GetLastElement().GetX() + 1;
	unsigned int renderCursorY = inputLog->GetLastElement().GetY();
	unsigned int prevRenderCursorX = inputLog->GetFirstElement().GetX() + 1;
	unsigned int prevRenderCursorY = inputLog->GetFirstElement().GetY();

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			m_RenderTarget[y][x] = " ";
		}
	}

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			// 숫자 설정
			if (x == 0)
			{
				if (y != 8)
				{
					m_RenderTarget[y][x] = szLeft[y];
				}
			}

			// 알파벳 설정
			if (y == 8)
			{
				if (x != 0)
				{
					m_RenderTarget[y][x] = szBottom[x - 1];
				}
			}

			piece = board->GetChessPiece(x, y);

			// 말 설정.
			m_RenderTarget[y][x + 1] = ToChar(piece);
		}
	}

	if (selectedPiece != nullptr)
	{
		// 선택된 말 설정.
		m_RenderTarget[selectedPiece->GetPosition().GetY()][selectedPiece->GetPosition().GetX() + 1] = "＠";
		ShowPath(board, selectedPiece);
	}

	// 커서 설정.
	m_RenderTarget[renderCursorY][renderCursorX] = "★";



	// 전체 그리기
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (x == 0 || y == 8)
			{
				// 흰색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << m_RenderTarget[y][x];
				continue;
			}

			if (board->m_Board[x - 1][y] == 0)
			{
				// 검은색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				if (board->m_Board[x - 1][y]->GetTeam() == ChessPieces::Black)
				{
					// 노랑색
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				}

				if (board->m_Board[x - 1][y]->GetTeam() == ChessPieces::White)
				{
					// 파란색
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				}
			}

			// 선택된 말의 이동 경로.
			if (selectedPiece != nullptr)
			{
				unsigned int pathCount = selectedPiece->GetPathCount(board->m_Board);
				Vector2<int>* paths = selectedPiece->GetPaths(board->m_Board, pathCount);

				for (unsigned int i = 0; i < pathCount; i++)
				{
					if (paths[i].GetY() == y && paths[i].GetX() + 1 == x)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					}
				}
			}

			// 커서
			if (x == renderCursorX && y == renderCursorY)
			{
				// 옥색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			}

			cout << m_RenderTarget[y][x];
		}
		cout << '\n';

	}

	RenderInformation(team, gameover);

	return true;
}

void ChessGraphics::Shutdown()
{
	return;
}

char* ChessGraphics::ToChar(const ChessPieces* piece)
{
	if (piece == 0)
	{
		return "  ";
	}
	else
	{
		switch (piece->GetType())
		{
		case ChessPieces::King:
			return "킹";
		case ChessPieces::Queen:
			return "퀸";
		case ChessPieces::Bishop:
			return "숍";
		case ChessPieces::Rook:
			return "룩";
		case ChessPieces::Knight:
			return "나";
		case ChessPieces::Pawn:
			return "폰";
		default:
			return "  ";
		}
	}

	return NULL;
}

void ChessGraphics::ShowPath(ChessBoard* board, const ChessPieces* piece)
{
	unsigned int pathCount = piece->GetPathCount(board->m_Board);
	Vector2<int>* paths = piece->GetPaths(board->m_Board, pathCount);

	for (unsigned int i = 0; i < pathCount; i++)
	{
		m_RenderTarget[paths[i].GetY()][paths[i].GetX() + 1] = "◆";
	}
}

void ChessGraphics::RenderInformation(const int& team, const bool& gameover)
{
	using namespace std;

	cout << "\n";
	cout << "\n";
	cout << "\n";

	int turnColor = 0;
	char* teamText = nullptr;
	teamText = (team > 0) ? "BLACK" : "WHITE";

	turnColor = (team > 0) ? 6 : 1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "TURN : ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), turnColor);

	cout << teamText;
	cout << "\n";

	if (gameover)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "WINNER : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), turnColor);
		cout << teamText;
		cout << "\n";
	}
}
