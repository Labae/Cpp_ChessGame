#pragma once
template<typename T>
struct Element
{
	T element;
	Element* next;
};

template<typename T>
class Queue
{
public:
	Queue();
	~Queue();
	Queue(const Queue<T>& input);

	bool operator== (const Queue<T>& other) const;
	bool operator!= (const Queue<T>& other) const;

	void Enqueue(T input);
	T Dequeue();
	T GetFirstElement();
	T GetLastElement();
	T GetElement(int index);
	int GetCount();

private:
	Element<T>* m_HeadElement;
	int m_Count;
};

template<typename T>
inline Queue<T>::Queue() : m_HeadElement(0), m_Count(0)
{
}

template<typename T>
inline Queue<T>::~Queue()
{
	if (m_HeadElement)
	{
		Element<T>* pt = m_HeadElement;
		// Shift
		for (int index = 0; index < m_Count - 1; index++)
		{
			Element<T>* delElement = pt;
			pt = pt->next;

			delete delElement;
			delElement = 0;
		}

		delete m_HeadElement;
		m_HeadElement = 0;
	}
}

template<typename T>
inline Queue<T>::Queue(const Queue<T>& input) : m_HeadElement(input.m_HeadElement), m_Count(input.m_Count)
{
}

template<typename T>
inline bool Queue<T>::operator==(const Queue<T>& other) const
{
	if (*this == other)
	{
		return true;
	}

	if (this->m_HeadElement == other.m_HeadElement && this->m_Count == other->m_Count)
	{
		return true;
	}

	return false;
}

template<typename T>
inline bool Queue<T>::operator!=(const Queue<T>& other) const
{
	if (*this != other)
	{
		return true;
	}

	if (this->m_HeadElement != other.m_HeadElement || this->m_Count != other.m_Count)
	{
		return true;
	}

	return false;
}

template<typename T>
inline void Queue<T>::Enqueue(T input)
{
	// 맨 처음 넣을때
	if (m_Count == 0)
	{
		m_HeadElement = new Element<T>();
		m_HeadElement->element = input;
		m_HeadElement->next = nullptr;
	}
	else
	{
		Element<T>* pt = m_HeadElement;
		for (int i = 0; i < m_Count - 1; i++)
		{
			pt = pt->next;
		}

		Element<T>* addedElement = new Element<T>();
		addedElement->element = input;
		addedElement->next = nullptr;

		pt->next = addedElement;
	}

	m_Count++;
}

template<typename T>
inline T Queue<T>::Dequeue()
{
	m_Count--;

	if (m_HeadElement)
	{
		Element<T>* result = m_HeadElement;
		m_HeadElement = result->next;

		delete result;
		return m_HeadElement->element;
	}
	else
	{
		return T();
	}
}

template<typename T>
inline T Queue<T>::GetFirstElement()
{
	return m_HeadElement->element;
}

template<typename T>
inline T Queue<T>::GetLastElement()
{
	Element<T>* result = m_HeadElement;
	for (int i = 0; i < m_Count - 1; i++)
	{
		result = result->next;
	}

	return result->element;
}

template<typename T>
inline T Queue<T>::GetElement(int index)
{
	Element<T>* result = m_HeadElement;
	for (int i = 0; i < index; i++)
	{
		result = result->next;
	}

	return result->element;
}

template<typename T>
inline int Queue<T>::GetCount()
{
	return m_Count;
}

