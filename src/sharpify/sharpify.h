#ifndef _SHARPIFY_H_
#define _SHARPIFY_H_
#include <vector>
//New name for this file should be "sharpify"

namespace std
{
	template <class T>
	class Vector : public std::vector<T>
	{
	private:
		
		//static Vector<T> _matches;

	public:

		Vector<T>()
		{

		}

		template <class G>
		const vector<T>& forEach(const G& function)
		{
			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				function(*iterator);
			}

			return *this;
		}

		template <class G>
		const Vector<T> where(const G& predicate)
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

