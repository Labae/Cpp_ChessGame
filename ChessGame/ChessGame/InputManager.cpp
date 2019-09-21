#include "InputManager.h"

int InputManager::m_kPosX = 0;
int InputManager::m_kPosY = 0;

InputManager::InputManager() : m_InputPositionLog(0), m_Selected(false), m_SelectedPiece(0)
{
}

InputManager::~InputManager()
{
}

bool InputManager::Initialize()
{
	m_InputPositionLog = new Queue<Vector2<int>>();
	m_InputPositionLog->Enqueue(Vector2<int>(-1, -1));
	m_InputPositionLog->Enqueue(Vector2<int>(0, 0));

	return true;
}

void InputManager::Shutdown()
{
	if (m_InputPositionLog)
	{
		delete m_InputPositionLog;
		m_InputPositionLog = 0;
	}
}

void InputManager::Input(ChessBoard* board, int& team)
{
	while (true)
	{
		if (_kbhit())
		{
			int nKey = _getch();
			
			ChessPieces* piece = 0;

			switch (nKey)
			{
				// UP
			case 72:
				if (m_kPosY <= 0)
				{
					return;
				}
				else
				{
					m_kPosY--;
					m_InputPositionLog->Enqueue(Vector2<int>(m_kPosX, m_kPosY));
					if (m_InputPositionLog->GetCount() >= 2)
					{
						Vector2<int> data = m_InputPositionLog->Dequeue();
					}
					return;
				}
				// Down
			case 80:
				if (m_kPosY >= 7)
				{
					return;
				}
				else
				{
					m_kPosY++;
					m_InputPositionLog->Enqueue(Vector2<int>(m_kPosX, m_kPosY));
					if (m_InputPositionLog->GetCount() >= 2)
					{
						Vector2<int> data = m_InputPositionLog->Dequeue();
					}
					return;
				}
				// Left
			case 75:
				if (m_kPosX <= 0)
				{
					return;
				}
				else
				{
					m_kPosX--;
					m_InputPositionLog->Enqueue(Vector2<int>(m_kPosX, m_kPosY));
					if (m_InputPositionLog->GetCount() >= 2)
					{
						Vector2<int> data = m_InputPositionLog->Dequeue();
					}
					return;
				}
				// Right
			case 77:
				if (m_kPosX >= 7)
				{
					return;
				}
				else
				{
					m_kPosX++;
					m_InputPositionLog->Enqueue(Vector2<int>(m_kPosX, m_kPosY));
					if (m_InputPositionLog->GetCount() >= 2)
					{
						Vector2<int> data = m_InputPositionLog->Dequeue();
					}
					return;
				}
				// SpaceBar
			case 32:
				piece = board->GetChessPiece(m_kPosX, m_kPosY);

				if (piece != nullptr)
				{
					// 이미 선택되어 있다면 다른 것들 선택 불가능.
					if (m_Selected)
					{
						// 선택 취소
						if (piece->IsSelected())
						{
							piece->UnSelect();
							m_Selected = false;
							m_SelectedPiece = nullptr;
							return;
						}

						// 공격하기.
						if (m_SelectedPiece != nullptr)
						{
							if (m_SelectedPiece->GetTeam() != piece->GetTeam())
							{
								unsigned int pathCount = m_SelectedPiece->GetPathCount(board->m_Board);
								Vector2<int>* paths = m_SelectedPiece->GetPaths(board->m_Board, pathCount);

								for (unsigned int i = 0; i < pathCount; i++)
								{
									if (paths[i].GetX() == m_kPosX && paths[i].GetY() == m_kPosY)
									{
										board->m_Board[m_SelectedPiece->GetPosition().GetX()][m_SelectedPiece->GetPosition().GetY()] = nullptr;
										m_SelectedPiece->Move(m_kPosX, m_kPosY);
										board->m_Board[m_SelectedPiece->GetPosition().GetX()][m_SelectedPiece->GetPosition().GetY()] = m_SelectedPiece;
									}
								}

								team = (m_SelectedPiece->GetTeam() > 0) ? ChessPieces::White : ChessPieces::Black;

								m_SelectedPiece->UnSelect();
								m_Selected = false;
								m_SelectedPiece = nullptr;
							}
						}
					}
					else
					{
						if (piece->GetTeam() == team)
						{
							// 선택하기.
							if (!piece->IsSelected())
							{
								piece->Select();
								m_Selected = true;
								m_SelectedPiece = piece;
								return;
							}
						}
					}
				}
				else
				{
					if (m_SelectedPiece != nullptr)
					{
						unsigned int pathCount = m_SelectedPiece->GetPathCount(board->m_Board);
						Vector2<int>* paths = m_SelectedPiece->GetPaths(board->m_Board, pathCount);

						for (unsigned int i = 0; i < pathCount; i++)
						{
							if (paths[i].GetX() == m_kPosX && paths[i].GetY() == m_kPosY)
							{
								board->m_Board[m_SelectedPiece->GetPosition().GetX()][m_SelectedPiece->GetPosition().GetY()] = nullptr;
								m_SelectedPiece->Move(m_kPosX, m_kPosY);
								board->m_Board[m_SelectedPiece->GetPosition().GetX()][m_SelectedPiece->GetPosition().GetY()] = m_SelectedPiece;
							}
						}

						team = (m_SelectedPiece->GetTeam() > 0) ? ChessPieces::White : ChessPieces::Black;

						m_SelectedPiece->UnSelect();
						m_Selected = false;
						m_SelectedPiece = nullptr;
					}
				}
				return;
				// Escape
			case 27:
				exit(0);
				return;
			default:
				return;
			}
		}
	}
}

int InputManager::GetPosX()
{
	if (m_kPosX < 0)
	{
		return 0;
	}
	else if (m_kPosX >= 8)
	{
		return 7;
	}
	else
	{
		return m_kPosX;
	}
}

int InputManager::GetPosY()
{
	if (m_kPosY < 0)
	{
		return 0;
	}
	else if (m_kPosY >= 8)
	{
		return 7;
	}
	else
	{
		return m_kPosY;
	}
}

bool InputManager::IsSelected()
{
	return m_Selected;
}

Queue<Vector2<int>>* InputManager::GetQueue()
{
	return m_InputPositionLog;
}

ChessPieces* InputManager::GetSelectedPiece()
{
	return m_SelectedPiece;
}
