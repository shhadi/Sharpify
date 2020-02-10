#ifndef _SHARPIFY_H_
#define _SHARPIFY_H_
#include <vector>
#include<utility>

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

		template <class G>
		void forEach(const G& function)const
		{
			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				function(*iterator);
			}
		}

		template <class G>
		const Vector<T> where(const G& predicate)const
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

