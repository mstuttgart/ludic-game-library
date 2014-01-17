#ifndef _SGL_LOGOUT_
#define _SGL_LOGOUT_

#include <fstream>

namespace sgl {

class LogOutput {

private:

	static std::ofstream log_file; /**<< ofstream obeject for output log.*/

public:

	/**
	 * @brief Print the char mensage in SagaGameLibrary.log file.
	 * @param msg Mensage that be write in SagaGameLibrary.log file..
	 */
	static void printInLogout( const char* msg );


	/**
	 * @brief Default Destructor
	 */
	virtual ~LogOutput() {};

};

} /* Namespace */

#endif
