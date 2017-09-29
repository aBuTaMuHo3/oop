#include "stdafx.h"
#include "../Auto/CarController.h"
#include "../Auto/Car.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// «ависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструировани€ самого remote-контрола
struct CCarControllerDependencies
{
	CCar car;
	stringstream input;
	stringstream output;
};

struct CarControllerFixture : CCarControllerDependencies
{
	CCarController remoteControl;

	CarControllerFixture()
		: remoteControl(car, input, output)
	{
	}

	// ¬спомогательна€ функци€ дл€ проверки работы команды command
	// ќна принимает ожидаемый номер канала expectedChannel и expectedOutput
	void VerifyCommandHandling(const string& command, const string& expectedOutput)
	{
		// ѕредварительно очищаем содержимое выходного потока
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Car_controller, CarControllerFixture)

	BOOST_AUTO_TEST_CASE(can_handle_EngineOn_command)
	{
		VerifyCommandHandling("EngineOn", "");
	}

	BOOST_AUTO_TEST_CASE(can_handle_Info_command)
	{
		VerifyCommandHandling("Info", "Engine is turned off\n");
	}

	BOOST_AUTO_TEST_CASE(can_print_SetGear_command_error_messages)
	{
		VerifyCommandHandling("SetGear 1", "Engine is turned off or gear does not match current speed\n");
	}
	BOOST_AUTO_TEST_CASE(can_print_EngineOff_command_error_messages_1)
	{
		VerifyCommandHandling("EngineOff", "Engine is already off\n");
	}

	BOOST_AUTO_TEST_CASE(can_print_EngineOff_command_error_messages_2)
	{
		car.TurnOnEngine();
		car.SetGear(1);
		VerifyCommandHandling("EngineOff", "Engine can be turned off only at 0 speed and 0 gear\n");
	}

	BOOST_AUTO_TEST_CASE(can_handle_SetSpeed_command)
	{
		car.TurnOnEngine();
		car.SetGear(1);
		VerifyCommandHandling("SetSpeed 30", "");
	}

	BOOST_AUTO_TEST_CASE(can_handle_SetSpeed_command_error_message)
	{
		car.TurnOnEngine();
		car.SetGear(1);
		VerifyCommandHandling("SetSpeed 60", "Speed is out of available range for 1 gear\n");
	}
BOOST_AUTO_TEST_SUITE_END()