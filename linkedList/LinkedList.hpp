/**
*	@author Jarrett Zeliff
*	@date 9/01/2020
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{

	return(m_size); // just returns size
	return(0);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	if (m_front == nullptr)
	{
		return (false); // wont return if list is empty
	}

	Node<T>* temp = m_front;
	bool isFound = false;

	while (temp != nullptr) //checks throughout the entire list until the end
	{
		if (temp->getValue() == value)
		{
			isFound = true;
			return (isFound);
		}
		temp = temp->getNext();
	}
	return(isFound);

}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	Node<T>* temp = nullptr;
	bool isRemoved = false;
	lastNode = m_front;
	secondintoLast = m_front;
	if (m_front == nullptr)
	{
		return(false); // if its empty, return false
	}

	else if (m_front->getNext() == nullptr)
	{
		temp = m_front;
		delete temp;
		isRemoved = true;
		m_size = m_size-1;
		return (isRemoved); // if there is only one node, delete is and return false
	}
	else
	{
		while (lastNode->getNext() != nullptr)
		{
			lastNode = lastNode->getNext();
			if (lastNode->getNext() !=nullptr)
			{
				secondintoLast = lastNode; 
			}
		}
		secondintoLast->setNext(temp); // makes second to last nodes next value nullptr
		delete lastNode; // deletes the actual last node
	}
	m_size = m_size-1;
	isRemoved = true;
	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
