#ifndef _SHARPIFY_H_
#define _SHARPIFY_H_
#include <vector>
#include<utility>
#include <functional>
#include<iostream>

namespace std
{
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
	};


}

#define vector Vector

#endif

