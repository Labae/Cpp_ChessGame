#include "Bishop.h"

Bishop::Bishop(unsigned int team) : ChessPieces(ChessPieces::Bishop, team, false)
{
}

void Bishop::Move(const int& moveX, const int& moveY)
{
	SetPosition(moveX, moveY);
}

Vector2<int>* Bishop::CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	Vector2<int>* result = new Vector2<int>[pathCount];
	unsigned int count = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;
	int length = 0;

	// ������
	if (7 - currentPosX >= currentPosY)
	{
		length = currentPosY;
	}
	else
	{
		length = 7 - currentPosX;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX + index][currentPosY - index];
		if (piece == nullptr)
		{
			result[count++] = Vector2<int>(currentPosX + index, currentPosY - index);
		}
		else
		{
			if (piece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(currentPosX + index, currentPosY - index);
			}

			break;
		}
	}

	// �����Ʒ�
	if (currentPosX > currentPosY)
	{
		length = 7 - currentPosX;
	}
	else
	{
		length = 7 - currentPosY;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX + index][currentPosY + index];
		if (piece == nullptr)
		{
			result[count++] = Vector2<int>(currentPosX + index, currentPosY + index);
		}
		else
		{
			if (piece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(currentPosX + index, currentPosY + index);
			}

			break;
		}
	}

	// ����
	if (currentPosX > currentPosY)
	{
		length = currentPosY;
	}
	else
	{
		length = currentPosX;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX - index][currentPosY - index];
		if (piece == nullptr)
		{
			result[count++] = Vector2<int>(currentPosX - index, currentPosY - index);
		}
		else
		{
			if (piece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(currentPosX - index, currentPosY - index);
			}

			break;
		}
	}

	// �޾Ʒ�
	if (7 - currentPosX >= currentPosY)
	{
		length = currentPosX;
	}
	else
	{
		length = 7 - currentPosY;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX - index][currentPosY + index];
		if (piece == nullptr)
		{
			result[count++] = Vector2<int>(currentPosX - index, currentPosY + index);
		}
		else
		{
			if (piece->GetTeam() != GetTeam())
			{
				result[count++] = Vector2<int>(currentPosX - index, currentPosY + index);
			}

			break;
		}
	}

	return result;
}

unsigned int Bishop::CalcuratePathCount(ChessPieces* (*board)[8]) const
{
	unsigned int result = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;
	int length = 0;

	// ������
	if (7 - currentPosX >= currentPosY)
	{
		length = currentPosY;
	}
	else
	{
		length = 7 - currentPosX;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX + index][currentPosY - index];
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

			break;
		}
	}

	// �����Ʒ�
	if (currentPosX > currentPosY)
	{
		length = 7 - currentPosX;
	}
	else
	{
		length = 7 - currentPosY;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX + index][currentPosY + index];
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

			break;
		}
	}

	// ����
	if (currentPosX > currentPosY)
	{
		length = currentPosY;
	}
	else
	{
		length = currentPosX;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX - index][currentPosY - index];
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

			break;
		}
	}

	// �޾Ʒ�
	if (7 - currentPosX >= currentPosY)
	{
		length = currentPosX;
	}
	else
	{
		length = 7 - currentPosY;
	}
	for (int index = 1; index <= length; index++)
	{
		piece = board[currentPosX - index][currentPosY + index];
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

			break;
		}
	}

	return result;
}
