#include "Knight.h"

Knight::Knight(unsigned int team) : ChessPieces(ChessPieces::Knight, team, false)
{
}

void Knight::Move(const int& moveX, const int& moveY)
{
	SetPosition(moveX, moveY);
}

Vector2<int>* Knight::CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	Vector2<int>* result = new Vector2<int>[pathCount];
	unsigned int count = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;

	if (currentPosX - 2 >= 0)
	{
		if (currentPosY - 1 >= 0)
		{
			piece = board[currentPosX - 2][currentPosY - 1];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX - 2, currentPosY - 1);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX - 2, currentPosY - 1);
				}
			}
		}

		if (currentPosY + 1 <= 7)
		{
			piece = board[currentPosX - 2][currentPosY + 1];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX - 2, currentPosY + 1);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX - 2, currentPosY + 1);
				}
			}
		}
	}

	if (currentPosX - 1 >= 0)
	{
		if (currentPosY - 2 >= 0)
		{
			piece = board[currentPosX - 1][currentPosY - 2];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX - 1, currentPosY - 2);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX - 1, currentPosY - 2);
				}
			}
		}

		if (currentPosY + 2 <= 7)
		{
			piece = board[currentPosX - 1][currentPosY + 2];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX - 1, currentPosY + 2);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX - 1, currentPosY + 2);
				}
			}
		}
	}

	if (currentPosX + 1 <= 7)
	{
		if (currentPosY - 2 >= 0)
		{
			piece = board[currentPosX + 1][currentPosY - 2];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX + 1, currentPosY - 2);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX + 1, currentPosY - 2);
				}
			}
		}

		if (currentPosY + 2 <= 7)
		{
			piece = board[currentPosX + 1][currentPosY + 2];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX + 1, currentPosY + 2);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX + 1, currentPosY + 2);
				}
			}
		}
	}

	if (currentPosX + 2 <= 7)
	{
		if (currentPosY - 1 >= 0)
		{
			piece = board[currentPosX + 2][currentPosY - 1];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX + 2, currentPosY - 1);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX + 2, currentPosY - 1);
				}
			}
		}

		if (currentPosY + 1 <= 7)
		{
			piece = board[currentPosX + 2][currentPosY + 1];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(currentPosX + 2, currentPosY + 1);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(currentPosX + 2, currentPosY + 1);
				}
			}
		}
	}

	return result;
}

unsigned int Knight::CalcuratePathCount(ChessPieces* (*board)[8]) const
{
	unsigned int result = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;

	if (currentPosX - 2 >= 0)
	{
		if (currentPosY - 1 >= 0)
		{
			piece = board[currentPosX - 2][currentPosY - 1];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}
		
		if (currentPosY + 1 <= 7)
		{
			piece = board[currentPosX - 2][currentPosY + 1];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}
	}

	if (currentPosX - 1 >= 0)
	{
		if (currentPosY - 2 >= 0)
		{
			piece = board[currentPosX - 1][currentPosY - 2];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}

		if (currentPosY + 2 <= 7)
		{
			piece = board[currentPosX - 1][currentPosY + 2];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}
	}

	if (currentPosX + 1 <= 7)
	{
		if (currentPosY - 2 >= 0)
		{
			piece = board[currentPosX + 1][currentPosY - 2];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}

		if (currentPosY + 2 <= 7)
		{
			piece = board[currentPosX + 1][currentPosY + 2];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}
	}

	if (currentPosX + 2 <= 7)
	{
		if (currentPosY - 1 >= 0)
		{
			piece = board[currentPosX + 2][currentPosY - 1];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}

		if (currentPosY + 1 <= 7)
		{
			piece = board[currentPosX + 2][currentPosY + 1];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}
	}

	return result;
}
