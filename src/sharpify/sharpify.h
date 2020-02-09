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
		vector<T> _matches;
	public:

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
		const Vector<T>& where(const G& predicate)
		{
			_matches = vector<T>();

			for (auto iterator = this->begin(); iterator != this->end(); ++iterator)
			{
				if (predicate(*iterator))
				{
					_matches.push_back(*iterator);
				}
			}
			return _matches;
		}

	};
}

#define vector Vector

#endif

