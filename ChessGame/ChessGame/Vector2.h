#pragma once
template<typename T>
class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2(T x, T y);
	Vector2(const Vector2<T>& input);


	Vector2<T>& operator= (const Vector2<T>& input);
	const Vector2<T> operator+ (const Vector2<T>& input);
	const Vector2<T> operator- (const Vector2<T>& input);
	const Vector2<T> operator* (const Vector2<T>& input);
	const Vector2<T> operator/ (const Vector2<T>& input);
	bool operator== (const Vector2<T>& other) const;
	bool operator!= (const Vector2<T>& other) const;

	T GetX() const;
	T GetY() const;

	void SetX(T x);
	void SetY(T y);
	void SetXY(T x, T y);

private:
	T m_X;
	T m_Y;
};


template <typename T>
Vector2<T>::Vector2() : m_X(0), m_Y(0)
{

}


template <typename T>
Vector2<T>::~Vector2()
{

}

template<typename T>
Vector2<T>::Vector2(T x, T y) : m_X(x), m_Y(y)
{
}

template<typename T>
Vector2<T>::Vector2(const Vector2<T>& input) : m_X(input.m_X), m_Y(input.m_Y)
{

}

template<typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& input)
{
	if (this == &input)
	{
		return *this;
	}

	// TODO: 여기에 반환 구문을 삽입합니다.
	this->m_X = input.m_X;
	this->m_Y = input.m_Y;

	return *this;
}

template<typename T>
const Vector2<T> Vector2<T>::operator+(const Vector2<T>& input)
{
	Vector2<T> result = *this;
	result->m_X += input.m_Y;
	result->m_Y += input.m_Y;

	return result;
}

template<typename T>
const Vector2<T> Vector2<T>::operator-(const Vector2<T>& input)
{
	Vector2<T> result = *this;
	result->m_X -= input.m_Y;
	result->m_Y -= input.m_Y;

	return result;
}

template<typename T>
const Vector2<T> Vector2<T>::operator*(const Vector2<T>& input)
{
	Vector2<T> result = *this;
	result->m_X *= input.m_Y;
	result->m_Y *= input.m_Y;

	return result;
}

template<typename T>
const Vector2<T> Vector2<T>::operator/(const Vector2<T>& input)
{
	Vector2<T> result = *this;
	result->m_X /= input.m_Y;
	result->m_Y /= input.m_Y;

	return result;
}

template<typename T>
bool Vector2<T>::operator==(const Vector2<T>& other) const
{
	if (*this == other)
	{
		return true;
	}

	if (this->m_X == other.m_X && this->m_Y == other.m_Y)
	{
		return true;
	}

	return false;
}

template<typename T>
bool Vector2<T>::operator!=(const Vector2<T>& other) const
{
	if (*this != other)
	{
		return true;
	}

	if (this->m_X != other.m_X || this->m_Y != other.m_Y)
	{
		return true;
	}

	return false;
}

template<typename T>
T Vector2<T>::GetX() const
{
	return m_X;
}

template<typename T>
T Vector2<T>::GetY() const
{
	return m_Y;
}

template<typename T>
inline void Vector2<T>::SetX(T x)
{
	m_X = x;
}

template<typename T>
inline void Vector2<T>::SetY(T y)
{
	m_Y = y;
}

template<typename T>
inline void Vector2<T>::SetXY(T x, T y)
{
	m_X = x;
	m_Y = y;
}

