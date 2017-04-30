#include <queue>
#include <mutex>
using namespace std;

template <typename t>
class queueWithMutex {
	private:
	queue<t> q;
	mutex m;
	public:
	queue()
	{
		//i don't know what should be here. thing that nothing
	}
	
	bool push(const t stuff) {
		if(m.try_lock()) {
			q.push(stuff);
			m.unlock();
			return true;
		}
		else {
			return false;
		}
	}
	
	bool pop(t &stuff) {
		if(m.try_lock()) {
			stuff = q.front();
			m.unlock();
			return true;
		}
		else {
			return false;
		}
	}
}