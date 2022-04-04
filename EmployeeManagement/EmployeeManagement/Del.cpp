#include <algorithm>
#include "Del.h"
#include "MemoryDatabase.h"

vector<shared_ptr<Employee>> deleteById(string first_option, string id)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::EMPLOYEE_NUM, id));
	db.remove({ id });

	return result;
}

int deleteById(string id)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::EMPLOYEE_NUM, id));
	db.remove({ id });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByFullName(string first_option, string name)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::NAME, name));
	db.remove({ name });

	return result;
}

int deleteByFullName(string name)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::NAME, name));
	db.remove({ name });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByFirstName(string first_option, string name)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::FIRST_NAME, name));
	db.remove({ name });

	return result;
}

int deleteByFirstName(string name)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::FIRST_NAME, name));
	db.remove({ name });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByLastName(string first_option, string name)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::LAST_NAME, name));
	db.remove({ name });

	return result;
}

int deleteByLastName(string name)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::LAST_NAME, name));
	db.remove({ name });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByFullPhone(string first_option, string phone)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::TEL, phone));
	db.remove({ phone });

	return result;
}

int deleteByFullPhone(string phone)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::TEL, phone));
	db.remove({ phone });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByMiddlePhone(string first_option, string phone)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::TEL_MIDDLE, phone));
	db.remove({ phone });

	return result;
}

int deleteByMiddlePhone(string phone)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::TEL_MIDDLE, phone));
	db.remove({ phone });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByLastPhone(string first_option, string phone)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::TEL_LAST, phone));
	db.remove({ phone });

	return result;
}

int deleteByLastPhone(string phone)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::TEL_LAST, phone));
	db.remove({ phone });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByFullBirth(string first_option, string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH, birth));
	db.remove({ birth });

	return result;
}

int deleteByFullBirth(string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH, birth));
	db.remove({ birth });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByYearBirth(string first_option, string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH_YEAR, birth));
	db.remove({ birth });

	return result;
}

int deleteByYearBirth(string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH_YEAR, birth));
	db.remove({ birth });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByMonthBirth(string first_option, string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH_MONTH, birth));
	db.remove({ birth });

	return result;
}

int deleteByMonthBirth(string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH_MONTH, birth));
	db.remove({ birth });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByDayBirth(string first_option, string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH_DAY, birth));
	db.remove({ birth });

	return result;
}

int deleteByDayBirth(string birth)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::BIRTH_DAY, birth));
	db.remove({ birth });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByCl(string first_option, string cl)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::CL, cl));
	db.remove({ cl });

	return result;
}

int deleteByCl(string cl)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::CL, cl));
	db.remove({ cl });

	return result.size();
}

vector<shared_ptr<Employee>> deleteByCerti(string first_option, string certi)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::CERTI, certi));
	db.remove({ certi });

	return result;
}

int deleteByCerti(string certi)
{
	MemoryDatabase db;

	auto result = db.query(Filter(Filter::Column::CERTI, certi));
	db.remove({ certi });

	return result.size();
}