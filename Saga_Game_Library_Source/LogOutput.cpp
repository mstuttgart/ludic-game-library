#include "LogOutput.h"

namespace sgl {
	
std::ofstream LogOutput::log_file( "SagaGameLibrary.log" );

void LogOutput::printInLogout( const char* msg ) {
	log_file << __TIME__ << " " << __FILE__ << " " << msg << std::endl;
}

}//namespace
