#include <iostream>
using namespace std;
template <typename T3>
class CArray3D
{
	template <typename T2>
	class CArray2D
	{
		template <typename T1>
		class CArray1D
		{
		public:
			CArray1D(int dim1)
			{
				dim1_ = dim1;
				head_ = new T1[dim1_];
			}
			~CArray1D()
			{
				delete[]head_;
			}
			T1& operator[](int location)
			{
				return head_[location];
			}
		private:
			T1* head_;
			int dim1_;
		};
	public:
		CArray2D(int dim1, int dim2)
		{
			dim1_ = dim1, dim2_ = dim2;
			head_ = new CArray1D<T2>*[dim1_];
			for (int i = 0;i < dim1_;i++)
			{
				head_[i] = new CArray1D<T2>(dim2_);
			}
		}
		~CArray2D()
		{
			delete[]head_;
		}
		CArray1D<T2>& operator[](int location)
		{
			return *head_[location];
		}

	private:
		CArray1D<T2>** head_;
		int dim1_, dim2_;
	};
public:
	CArray3D(int dim1, int dim2, int dim3)
	{
		dim1_ = dim1, dim2_ = dim2, dim3_ = dim3;
		head_ = new CArray2D<T3>*[dim1_];
		for (int i = 0;i < dim1_;i++)
		{
			head_[i] = new CArray2D<T3>(dim2_, dim3_);
		}
	}
	~CArray3D()
	{
		delete[]head_;
	}
	CArray2D<T3>& operator[](int location)
	{
		return *head_[location];
	}

private:
	CArray2D<T3>** head_;
	int dim1_, dim2_, dim3_;
};

int main()
{
	CArray3D<int> a(3, 4, 5);
	int No = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";
	return 0;
}