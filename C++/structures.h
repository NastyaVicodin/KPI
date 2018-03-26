using namespace std;

struct student_info 
	{
	std::string name;
	std::string last;
	int course;
	};

struct teacher_info 
	{
	std::string name;
	std::string last;
	};

struct laboratory_work_info 
	{
	int variant;
	int count_of_done_tasks;
	struct student_info *author;	
	};