#include "ChessManager.h"


ChessManager::ChessManager()
{
	m_ChessGraphics = 0;
	m_Input = 0;
	m_Board = 0;
	m_Team = ChessPieces::White;
}

ChessManager::ChessManager(const ChessManager& other)
{
	this->m_ChessGraphics = other.m_ChessGraphics;
	this->m_Input = other.m_Input;
	this->m_Board = other.m_Board;
	this->m_Team = other.m_Team;
}

bool ChessManager::Initialize()
{
	bool result;

	m_Board = new ChessBoard();
	if (!m_Board)
	{
		return false;
	}

	result = m_Board->Initialize();
	if (result)
	{
		return false;
	}

	m_ChessGraphics = new ChessGraphics();
	if(!m_ChessGraphics)
	{
		return false;
	}

	result = m_ChessGraphics->Initialize();
	if (!result)
	{
		return false;
	}

	m_Input = new InputManager();
	if (!m_Input)
	{
		return false;
	}

	result = m_Input->Initialize();
	if (!result)
	{
		return false;
	}

	return true;
}

bool ChessManager::Run()
{
	bool result;

	result = m_ChessGraphics->Render(m_Board, m_Input->GetQueue(), m_Input->GetSelectedPiece(), m_Team);
	if (!result)
	{
		return false;
	}

	m_Input->Input(m_Board, m_Team);

	return true;
}

void ChessManager::Shutdown()
{
	if (m_Board)
	{
		m_Board->Shutdown();
		delete m_Board;
		m_Board = 0;
	}

	if (m_Input)
	{
		m_Input->Shutdown();
		delete m_Input;
		m_Input = 0;
	}

	if (m_ChessGraphics)
	{
		m_ChessGraphics->Shutdown();
		delete m_ChessGraphics;
		m_ChessGraphics = 0;
	}
}
