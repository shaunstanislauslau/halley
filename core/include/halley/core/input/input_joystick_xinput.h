/*****************************************************************\
           __
          / /
		 / /                     __  __
		/ /______    _______    / / / / ________   __       __
	   / ______  \  /_____  \  / / / / / _____  | / /      / /
	  / /      | / _______| / / / / / / /____/ / / /      / /
	 / /      / / / _____  / / / / / / _______/ / /      / /
	/ /      / / / /____/ / / / / / / |______  / |______/ /
   /_/      /_/ |________/ / / / /  \_______/  \_______  /
                          /_/ /_/                     / /
			                                         / /
		       High Level Game Framework            /_/

  ---------------------------------------------------------------

  Copyright (c) 2007-2011 - Rodrigo Braz Monteiro.
  This file is subject to the terms of halley_license.txt.

\*****************************************************************/

#pragma once

#include "input_joystick.h"
#ifdef XINPUT_AVAILABLE

namespace Halley {

	// XInput implementation
	class InputJoystickXInput : public InputJoystick {
	public:
		~InputJoystickXInput();
		std::string getName() const override;

		bool isEnabled() const override { return enabled; }

		JoystickType getType() const override { return JOYSTICK_360; }
	
		void vibrate(spInputVibration vib) override;
		void stopVibrating() override;

	private:
		InputJoystickXInput(int number);

		void update(Time t) override;
		void setEnabled(bool enabled);

		void updateVibration(Time t);
		void setVibration(float high, float low);

		int index;
		int cooldown;
		bool enabled;
		time_t lastTime;

		std::vector<spInputVibration> vibs;

		friend class Input;
	};
}

#endif