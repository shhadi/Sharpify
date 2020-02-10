#ifndef _SHARPIFY_H_
#define _SHARPIFY_H_
#include <vector>
#include<utility>
#include <functional>

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

	};


}

#define vector Vector

#endif

