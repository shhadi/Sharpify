#ifndef _SHARPIFY_H_
#define _SHARPIFY_H_
#include <vector>
#include<utility>
#include <functional>
#include<iostream>
#include<string>

namespace std
{
	class String :public std::string
	{
	private:
	public:
		template<typename... Args>
		String(Args&&...args) : std::string(std::forward<Args>(args)...)
		{
		}

		bool startsWith(string s)
		{
			if (s.size() > this->size())
			{
				return false;
			}
			string start = substr(0, s.size());
			return s == start;
		}

		bool endsWith(string s)
		{
			if (s.size() > this->size())
			{
				return false;
			}
			string end = substr(size() - s.size(), size());
			return s == end;
		}
	
		string insertAt(int index, char ch)
		{
			insert(index, 1, ch);
			return *this;
		}
/*
		void padLeft(int count)
		{

		}

		void padRight(int count)
		{

		}
		*/
		//Remove(0);
		//Replace('a', 'k');
		//Split(char[] { 'a', 'b'});


		//ToCharArray();
		//ToLower();
		//ToUpper();
		//Trim();
		//TrimEnd();
		//TrimStart();
		
	    //string.IsNullOrWhiteSpace()
	};



	template <class T>
	class Vector : public std::vector<T>
	{
	private:

	public:

		template<typename... Args>
		Vector<T>(Args&&...args) : std::vector<T>(std::forward<Args>(args)...)
		{
		}

		Vector<T>(initializer_list<T> list):vector<T>(list)
		{
		}

		void forEach(const function<void(T)>& function)const
		{
			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				function(*iterator);
			}
		}

		//TODO: another C# version should be overloaded.
		const Vector<T> where(const function<bool(T)>& predicate)const
		{
			auto matches = Vector<T>();

			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				if (predicate(*iterator))
				{
					matches.push_back(*iterator);
				}
			}

			return matches;
		}

		const T aggregate(const function<T(T, T)>& function)const
		{
			T aggregation = T();

			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				aggregation = function(aggregation, *iterator);
			}

			return aggregation;
		}

		bool all(const function<bool(T)>& function)const
		{
			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				if (!function(*iterator))
				{
					return false;
				}
			}
			return true;
		}

		bool any(const function<bool(T)>& function)const
		{
			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				if (function(*iterator))
				{
					return true;
				}
			}
			return false;
		}


		Vector<T> concat(const Vector<T>& second)const
		{
			Vector<T> concatenatedSequence = Vector<T>(*this);
			second.forEach([&concatenatedSequence](T element) { concatenatedSequence.push_back(element); });
			return concatenatedSequence;
		}

		bool contains(const T& element)const
		{
			return this->any([&element](T e) {return e == element; });
		}

		int count(const function<bool(T)>& function)const
		{
			int count = 0;
			this->forEach([&count,&function](T element) {function(element) ? count++ : count; });
			return count;
		}
	};


}

#define vector Vector
#define string String

#endif

