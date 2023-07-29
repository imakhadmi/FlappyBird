#pragma once

constexpr float FLAP_SPEED = -2.75;				// Vertical speed added for flapping
constexpr float GRAVITY = 0.10f;

constexpr unsigned char BIRD_SIZE = 16;			// Height & Width
constexpr unsigned char BIRD_START_X = 37;		// Permanent bird horizontal position
constexpr unsigned char FONT_HEIGHT = 32;
constexpr unsigned char GAP_SIZE = 64;			// Gap size between pipes
constexpr unsigned char PIPE_OFFSET = 32;		// Minimum offset from the ground to the gap and from the top to the gap
constexpr unsigned char PIPE_SPEED = 1;
constexpr unsigned char SCREEN_RESIZE = 3;		// Game size multiplier

constexpr unsigned short NEW_PIPE_PERIOD = 128;	// Generate new pipes after this number of frames
constexpr unsigned short GROUND_OFFSET = 288;
constexpr unsigned short SCREEN_HEIGHT = 320;
constexpr unsigned short SCREEN_WIDTH = 180;