//Generic Segment Tree (w/ Lazy Propagation)
//by Conrad Soon
//Segment Tree implementation reference
//https://codeforces.com/blog/entry/18051
//Generic implementation reference
//https://codeforces.com/blog/entry/44478?#comment-290116
struct monoid //monoid implementation
{
	//value
	int val;
	//identity
	static int identity = 0;
	monoid b_op(const monoid &lhs, const monoid &rhs)
	{
		//associative, but not necessarily commutative binary operation
		monoid result;
		//EDIT HERE
		result.val = lhs.val + rhs.val;
		//END EDIT HERE
		return result;
	}
};

struct aggrOp
{
	monoid applyAggregate(){

	};
	void compose(){

	};
};

struct node
{
	//necessary
	monoid partialSum;
	monoid aggrVal;
	aggrOp f1;

	//additional useful variables
	int l;
	int r;

	//other shit you wanna add
};

class segTreeLP
{
}