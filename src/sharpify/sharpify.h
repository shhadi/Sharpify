#ifndef _SHARPIFY_
#define _SHARPIFY_
#include <vector>
//New name for this file should be "sharpify"

namespace std
{
	template <class T>
	class Vector : public std::vector<T>
	{	
	public:
		//template <class G>
		void where(T predicate)
		{
			auto result = find(this->begin(), this->end(), predicate);
		}
	};
}

#define vector Vector

#endif

