#include "time_handler.hpp"

using namespace Ludic;

//////////////////////////////////////////////////////////////

TimeHandler::TimeHandler() :
	startTicks( 0 ), pausedTicks( 0 ), started( false ), paused( false ) {}

//////////////////////////////////////////////////////////////

double TimeHandler::getTicks() const {

	// Se o timer foi iniciado
	if( started ) {

		// Se esta pausado, retornamos o instante que ocorreu a pausa
		if( paused )
			return pausedTicks;

		// Retornamos o instante que passou desde do inicio da contagem
		return ( al_get_time() - startTicks );

	}//if

	// Retorna 0 se o timer nao foi iniciado
	return 0;
}

//////////////////////////////////////////////////////////////

void TimeHandler::pause() {

	// Se o timer foi iniciado e nao esta pausado
	if( started && !paused ) {

		// Pausamos
		paused = true;

		// Capturamos o instante da pausa
		pausedTicks = al_get_time() - startTicks;

	}//if
}

//////////////////////////////////////////////////////////////

void TimeHandler::resume() {

	// Se estiver pausado
	if( paused ) {
		// Setamos pausado para false
		paused = false;

		// Calculamos o novo tempo de acordo com o instante da pausa
		startTicks = al_get_time() - pausedTicks;

		// Reiniciamos o pauseTickes
		pausedTicks = 0;

	}//if
}

//////////////////////////////////////////////////////////////

void TimeHandler::start() {

	// Iniciamos o flag start
	started = true;

	// Atualizamos o paused
	paused = false;

	// Capturamos o tempo atual
	startTicks = al_get_time();

}

//////////////////////////////////////////////////////////////

void TimeHandler::stop() {

	// Atualizamos flag started e resume
	started = false;
	paused  = false;
	startTicks  = 0;
	pausedTicks = 0;
}

//////////////////////////////////////////////////////////////

bool TimeHandler::isPaused() const {
	return paused;
}

//////////////////////////////////////////////////////////////

bool TimeHandler::isStarted() const {
	return started;
}

//////////////////////////////////////////////////////////////

void TimeHandler::sleep( double seconds ) {
	al_rest( seconds );
}

//////////////////////////////////////////////////////////////
