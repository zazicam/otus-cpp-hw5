// Framework specific classes

#include <iostream>

#ifndef TFORM
#define TFORM
class TForm {
public:
	void exec() {
		std::cout<<"Yeah! Editor compiled! :D"<<std::endl;
	}
};
#endif

#ifndef TTOOLBAR
#define TTOOLBAR
class TToolBar {};
#endif

#ifndef TMOUSEBUTTON
#define TMOUSEBUTTON
class TMouseButton {};
#endif

#ifndef TBITMAP
#define TBITMAP
class TBitmap {};
#endif

#ifndef TRECT
#define TRECT
class TRect {};
#endif

#ifndef TCOLOR
#define TCOLOR
class TColor {};
#endif

#ifndef TIMAGELIST
#define TIMAGELIST
class TImageList {};
#endif
//---------------------------

