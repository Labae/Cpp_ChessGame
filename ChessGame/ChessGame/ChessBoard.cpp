#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
}

ChessBoard::~ChessBoard()
{
}

bool ChessBoard::Initialize(bool standard)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_Board[i][j] = 0;
		}
	}

	if (standard)
	{
		unsigned int iCampTeam = ChessPieces::Black;
		unsigned int iCampPosition[2] = { 0,1 };

		for (unsigned int i = 0; i < 2; i++)
		{
			m_Board[0][iCampPosition[0]] = new Rook(iCampTeam);
			m_Board[1][iCampPosition[0]] = new Knight(iCampTeam);
			m_Board[2][iCampPosition[0]] = new Bishop(iCampTeam);
			m_Board[3][iCampPosition[0]] = new King(iCampTeam);
			m_Board[4][iCampPosition[0]] = new Queen(iCampTeam);
			m_Board[5][iCampPosition[0]] = new Bishop(iCampTeam);
			m_Board[6][iCampPosition[0]] = new Knight(iCampTeam);
			m_Board[7][iCampPosition[0]] = new Rook(iCampTeam);

			for (unsigned int j = 0; j < 8; j++)
			{
				m_Board[j][iCampPosition[0]]->SetPosition(j, iCampPosition[0]);

				m_Board[j][iCampPosition[1]] = new Pawn(iCampTeam);
				m_Board[j][iCampPosition[1]]->SetPosition(j, iCampPosition[1]);
			}

			iCampTeam = ChessPieces::White;
			iCampPosition[0] = 7;
			iCampPosition[1] = 6;
		}
	}

	for (unsigned int i = 0; i < 8; i++)
	{
		for (unsigned int j = 0; j < 8; j++)
		{
			if (m_Board[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

void ChessBoard::Shutdown()
{
	if (m_Board)
	{
		for (unsigned int i = 0; i < 8; i++)
		{
			for (unsigned int j = 0; j < 8; j++)
			{
				delete m_Board[i][j];
				m_Board[i][j] = 0;
			}
		}
	}
}

ChessPieces* ChessBoard::GetChessPiece(int x, int y)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
	{
		return m_Board[x][y];
	}

	return nullptr;
}