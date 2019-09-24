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

/// TODO : 2�� �迭�� �ؼ� �̰����� �����ؾ� �ҵ�.
bool ChessGraphics::Render(ChessBoard* board, Queue<Vector2<int>>* inputLog, ChessPieces* selectedPiece, const int& team, const bool& gameover)
{
	using namespace std;

	system("cls");

	char* szBottom[] = { "A ", "B ", "C ", "D ", "E ", "F ", "G ", "H " };
	char* szLeft[] = { "8","7","6","5","4","3","2","1" };
	ChessPieces* piece = 0;

	// Ŀ�� ��ǥ.
	unsigned int cursorPosX = inputLog->GetLastElement().GetX();
	unsigned int cursorPosY = inputLog->GetLastElement().GetY();
	unsigned int prevCursorPosX = inputLog->GetFirstElement().GetX();
	unsigned int prevCursorPosY = inputLog->GetFirstElement().GetY();

	// �������� Ŀ�� ��ǥ.
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
			// ���� ����
			if (x == 0)
			{
				if (y != 8)
				{
					m_RenderTarget[y][x] = szLeft[y];
				}
			}

			// ���ĺ� ����
			if (y == 8)
			{
				if (x != 0)
				{
					m_RenderTarget[y][x] = szBottom[x - 1];
				}
			}

			piece = board->GetChessPiece(x, y);

			// �� ����.
			m_RenderTarget[y][x + 1] = ToChar(piece);
		}
	}

	if (selectedPiece != nullptr)
	{
		// ���õ� �� ����.
		m_RenderTarget[selectedPiece->GetPosition().GetY()][selectedPiece->GetPosition().GetX() + 1] = "��";
		ShowPath(board, selectedPiece);
	}

	// Ŀ�� ����.
	m_RenderTarget[renderCursorY][renderCursorX] = "��";



	// ��ü �׸���
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (x == 0 || y == 8)
			{
				// ���
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << m_RenderTarget[y][x];
				continue;
			}

			if (board->m_Board[x - 1][y] == 0)
			{
				// ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				if (board->m_Board[x - 1][y]->GetTeam() == ChessPieces::Black)
				{
					// �����
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				}

				if (board->m_Board[x - 1][y]->GetTeam() == ChessPieces::White)
				{
					// �Ķ���
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				}
			}

			// ���õ� ���� �̵� ���.
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

			// Ŀ��
			if (x == renderCursorX && y == renderCursorY)
			{
				// ����
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
			return "ŷ";
		case ChessPieces::Queen:
			return "��";
		case ChessPieces::Bishop:
			return "��";
		case ChessPieces::Rook:
			return "��";
		case ChessPieces::Knight:
			return "��";
		case ChessPieces::Pawn:
			return "��";
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
		m_RenderTarget[paths[i].GetY()][paths[i].GetX() + 1] = "��";
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
