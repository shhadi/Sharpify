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
		const vector<T>& where(const G& predicate)
		{
			vector<T> matches = vector<T>();

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

