#include "Pawn.h"

Pawn::Pawn(unsigned int team) : ChessPieces(ChessPieces::Pawn, team, false), m_bFirst(true)
{
}

void Pawn::Move(const int& moveX, const int& moveY)
{
	if (m_bFirst)
	{
		m_bFirst = false;
	}

	m_Position.SetXY(moveX, moveY);
}

Vector2<int>* Pawn::CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	Vector2<int>* result = new Vector2<int>[pathCount];
	unsigned int count = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;

	if (m_bFirst)
	{
		if (GetTeam() == ChessPieces::Black)
		{
			for (int y = currentPosY + 1; y < currentPosY + 3; y++)
			{
				piece = board[currentPosX][y];

				if (piece == 0)
				{
					result[count++] = Vector2<int>(currentPosX, y);
				}
			}

			if (currentPosY + 1 <= 7)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX - 1, currentPosY + 1);
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX + 1, currentPosY + 1);
						}
					}
				}
			}
		}
		else
		{
			for (int y = currentPosY - 2; y < currentPosY; y++)
			{
				piece = board[currentPosX][y];

				if (piece == 0)
				{
					result[count++] = Vector2<int>(currentPosX, y);
				}
			}

			if (currentPosY - 1 >= 0)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY - 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX - 1, currentPosY - 1);
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY - 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX + 1, currentPosY - 1);
						}
					}
				}
			}
		}
	}
	else
	{
		if (GetTeam() == ChessPieces::Black)
		{
			piece = board[currentPosX][currentPosY + 1];

			if (piece == 0)
			{
				result[count++] = Vector2<int>(currentPosX, currentPosY + 1);
			}

			if (currentPosY + 1 <= 7)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX - 1, currentPosY + 1);
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX + 1, currentPosY + 1);
						}
					}
				}
			}
		}
		else
		{
			piece = board[currentPosX][currentPosY - 1];

			if (piece == 0)
			{
				result[count++] = Vector2<int>(currentPosX, currentPosY - 1);
			}

			if (currentPosY - 1 >= 0)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY - 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX - 1, currentPosY - 1);
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY - 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result[count++] = Vector2<int>(currentPosX + 1, currentPosY - 1);
						}
					}
				}
			}
		}
	}

	return result;
}

unsigned int Pawn::CalcuratePathCount(ChessPieces* (*board)[8]) const
{
	unsigned int result = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;

	if (m_bFirst)
	{
		if (GetTeam() == ChessPieces::Black)
		{
			for (int y = currentPosY + 1; y < currentPosY + 3; y++)
			{
				piece = board[currentPosX][y];

				if (piece == 0)
				{
					result++;
				}
			}

			if (currentPosY + 1 <= 7)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result++;
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result++;
						}
					}
				}
			}
		}
		else
		{
			for (int y = currentPosY - 2; y < currentPosY; y++)
			{
				piece = board[currentPosX][y];

				if (piece == 0)
				{
					result++;
				}

				if (currentPosY - 1 >= 0)
				{
					if (currentPosX - 1 >= 0)
					{
						piece = board[currentPosX - 1][currentPosY - 1];
						if (piece != nullptr)
						{
							if (piece->GetTeam() != GetTeam())
							{
								result++;
							}
						}
					}

					if (currentPosX + 1 <= 7)
					{
						piece = board[currentPosX + 1][currentPosY - 1];
						if (piece != nullptr)
						{
							if (piece->GetTeam() != GetTeam())
							{
								result++;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (GetTeam() == ChessPieces::Black)
		{
			piece = board[currentPosX][currentPosY + 1];

			if (piece == 0)
			{
				result++;
			}

			if (currentPosY + 1 <= 7)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result++;
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY + 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result++;
						}
					}
				}
			}
		}
		else
		{
			piece = board[currentPosX][currentPosY - 1];

			if (piece == 0)
			{
				result++;
			}

			if (currentPosY - 1 >= 0)
			{
				if (currentPosX - 1 >= 0)
				{
					piece = board[currentPosX - 1][currentPosY - 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result++;
						}
					}
				}

				if (currentPosX + 1 <= 7)
				{
					piece = board[currentPosX + 1][currentPosY - 1];
					if (piece != nullptr)
					{
						if (piece->GetTeam() != GetTeam())
						{
							result++;
						}
					}
				}
			}
		}
	}

	return result;
}
