#include "ChessPieces.h"

ChessPieces::ChessPieces() : m_iType(0), m_iTeam(0), m_bSelected(false)
{
}

ChessPieces::ChessPieces(unsigned int type, unsigned int team, bool selected) : m_iType(type), m_iTeam(team), m_bSelected(selected)
{
}

ChessPieces::~ChessPieces()
{
}

ChessPieces::ChessPieces(const ChessPieces& other)
{
	this->m_iTeam = other.m_iTeam;
	this->m_iType = other.m_iType;
	this->m_bSelected = other.m_bSelected;
}

ChessPieces& ChessPieces::operator=(const ChessPieces& other)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->m_iTeam = other.m_iTeam;
	this->m_iType = other.m_iType;
	this->m_bSelected = other.m_bSelected;

	return *this;
}

void ChessPieces::Shutdown()
{
}

unsigned int ChessPieces::GetType() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_iType;
}

unsigned int ChessPieces::GetTeam() const
{
	return m_iTeam;
}

bool ChessPieces::IsSelected() const
{
	return m_bSelected;
}

Vector2<int>* ChessPieces::GetPaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	return CalcuratePaths(board, pathCount);
}

unsigned int ChessPieces::GetPathCount(ChessPieces* (*board)[8]) const
{
	return CalcuratePathCount(board);
}

Vector2<int> ChessPieces::GetPosition()
{
	return m_Position;
}

Vector2<int>* ChessPieces::CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	return nullptr;
}

unsigned int ChessPieces::CalcuratePathCount(ChessPieces* (*board)[8]) const
{
	return 0;
}


void ChessPieces::Select()
{
	if (m_bSelected)
	{
		return;
	}

	m_bSelected = true;
}

void ChessPieces::UnSelect()
{
	if (!m_bSelected)
	{
		return;
	}

	m_bSelected = false;
}

void ChessPieces::SetPosition(int x, int y)
{
	m_Position.SetXY(x, y);
}

void ChessPieces::Move(const int& moveX, const int& moveY)
{
}
