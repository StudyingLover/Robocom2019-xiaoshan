#ifndef __DOUBLE_h
#define __DOUBLE_h



class Double
{
public:
	double data;
#define absError  0.001
	static bool IsEqual(double a, double b);
	int64_t TypeConversion()const;
	Double();
	Double(const double &a);



	operator int64_t() const
	{
		return TypeConversion();
	}

	operator double() const
	{
		return data;
	}



	template<typename T>
	operator T() const
	{
		return (T)data;
	}



	Double operator-() const
	{
		return -data;
	}

	Double operator+() const
	{
		return +data;
	}

	template<typename T>
	Double operator+=(const T v)
	{
		data += (double)v;
		return data;
	}

	template<typename T>
	Double operator-=(const T v)
	{
		data -= (double)v;
		return data;
	}

	template<typename T>
	Double operator*=(const T v)
	{
		data *= (double)v;
		return data;
	}

	template<typename T>
	Double operator/=(const T v)
	{
		data /= (double)v;
		return data;
	}



	template<typename T>
	Double operator+(const T v) const
	{
		return data + (double)v;
	}

	template<typename T>
	Double operator-(const T v) const
	{
		return data - (double)v;
	}

	template<typename T>
	Double operator*(const T v) const
	{
		return data*(double)v;
	}

	template<typename T>
	Double operator/(const T v) const
	{
		return data / (double)v;
	}


	template<typename T>
	bool operator>(const T v) const
	{
		return data > (double)v;
	}

	template<typename T>
	bool operator<(const T v) const
	{
		return data < (double)v;
	}

	template<typename T>
	bool operator>=(const T v) const
	{
		return data >= (double)v;
	}

	template<typename T>
	bool operator<=(const T v) const
	{
		return data <= (double)v;
	}

	template <typename T>
	bool operator ==(const T &v)
	{
		return IsEqual(data, (double)v);
	}

	template <typename T>
	bool operator !=(const T &v)
	{
		return !IsEqual(data, (double)v);
	}










	template <typename T>
	Double operator |(const T &v)
	{
		return (u32)data | (u32)v;
	}

	template <typename T>
	bool operator ||(const T &v)
	{
		return (u32)data || (u32)v;
	}

	template <typename T>
	Double operator &(const T &v)
	{
		return (u32)data & (u32)v;
	}

	template <typename T>
	bool operator &&(const T &v)
	{
		return (u32)data && (u32)v;
	}


	Double operator ++()
	{
		data += 1;
		return data;
	}

	Double operator ++(int)
	{
		data += 1;
		return data;
	}
};




template<typename T>
Double operator+(const T v1, const Double v2)
{
	return (double)v1 + v2.data;
}

template<typename T>
Double operator-(const T v1, const Double v2)
{
	return (double)v1 - v2.data;
}

template<typename T>
Double operator*(const T v1, const Double v2)
{
	return (double)v1 * v2.data;
}

template<typename T>
Double operator/(const T v1, const Double v2)
{
	return (double)v1 / v2.data;
}


template<typename T>
bool operator>(const T v1, const Double v2)
{
	return (double)v1 > v2.data;
}

template<typename T>
bool operator<(const T v1, const Double v2)
{
	return (double)v1 < v2.data;
}

template<typename T>
bool operator>=(const T v1, const Double v2)
{
	return (double)v1 >= v2.data;
}

template<typename T>
bool operator<=(const T v1, const Double v2)
{
	return (double)v1 <= v2.data;
}

template <typename T>
bool operator ==(const T v1, Double v2)
{
	return v2 == v1;
}

template <typename T>
bool operator !=(const T v1, Double v2)
{
	return 	v2 != v1;
}










template <typename T>
Double operator |(const T v1, Double v2)
{
	return (u32)v1 | (u32)v2;
}

template <typename T>
bool operator ||(const T v1, Double v2)
{
	return (u32)v1 || (u32)v2;
}

template <typename T>
Double operator &(const T v1, Double v2)
{
	return (u32)v1 & (u32)v2;
}

template <typename T>
bool operator &&(const T v1, Double v2)
{
	return (u32)v1 && (u32)v2;
}





#endif

