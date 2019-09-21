#include "Rook.h"

Rook::Rook(unsigned int team) : ChessPieces(ChessPieces::Rook, team, false)
{
}

void Rook::Move(const int& moveX, const int& moveY)
{
	SetPosition(moveX, moveY);
}

Vector2<int>* Rook::CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	Vector2<int>* result = new Vector2<int>[pathCount];
	unsigned int count = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* columPiece = 0;
	ChessPieces* rowPiece = 0;

	for (int x = currentPosX - 1; x >= 0; x--)
	{
		columPiece = board[x][currentPosY];
		if (columPiece == nullptr)
		{
			result[count++] = Vector2<int>(x, currentPosY);
		}
		else
		{
			if (columPiece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(x, currentPosY);
			}
			break;
		}
	}

	for (int x = currentPosX + 1; x < 8; x++)
	{
		columPiece = board[x][currentPosY];
		if (columPiece == nullptr)
		{
			result[count++] = Vector2<int>(x, currentPosY);
		}
		else
		{
			if (columPiece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(x, currentPosY);
			}
			break;
		}
	}

	for (int y = currentPosY - 1; y >= 0; y--)
	{
		rowPiece = board[currentPosX][y];
		if (rowPiece == nullptr)
		{
			result[count++] = Vector2<int>(currentPosX, y);
		}
		else
		{
			if (rowPiece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(currentPosX, y);
			}
			break;
		}
	}

	for (int y = currentPosY + 1; y < 8; y++)
	{
		rowPiece = board[currentPosX][y];
		if (rowPiece == nullptr)
		{
			result[count++] = Vector2<int>(currentPosX, y);
		}
		else
		{
			if (rowPiece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(currentPosX, y);
			}
			break;
		}
	}

	return result;
}

unsigned int Rook::CalcuratePathCount(ChessPieces* (*board)[8]) const
{
	unsigned int result = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* columPiece = 0;
	ChessPieces* rowPiece = 0;

	for (int x = currentPosX - 1; x >= 0; x--)
	{
		columPiece = board[x][currentPosY];
		if (columPiece == nullptr)
		{
			result++;
		}
		else
		{
			if (columPiece->GetTeam() != GetTeam())
			{
				result++;
			}

			break;
		}
	}

	for (int x = currentPosX + 1; x < 8; x++)
	{
		columPiece = board[x][currentPosY];
		if (columPiece == nullptr)
		{
			result++;
		}
		else
		{
			if (columPiece->GetTeam() != GetTeam())
			{
				result++;
			}
			break;
		}
	}

	for (int y = currentPosY - 1; y >= 0; y--)
	{
		rowPiece = board[currentPosX][y];
		if (rowPiece == nullptr)
		{
			result++;
		}
		else
		{
			if (rowPiece->GetTeam() != GetTeam())
			{
				result++;
			}
			break;
		}
	}

	for (int y = currentPosY + 1; y < 8; y++)
	{
		rowPiece = board[currentPosX][y];
		if (rowPiece == nullptr)
		{
			result++;
		}
		else
		{
			if (rowPiece->GetTeam() != GetTeam())
			{
				result++;
			}
			break;
		}
	}

	return result;
}
