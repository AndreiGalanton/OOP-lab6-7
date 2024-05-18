#pragma once

#include "Service.h"
#include <iostream>

class UI {
	Service& service;

public:
	UI(Service& service) noexcept : service{ service } {};
	UI(const UI& ui) = delete;

	void start();

	void printeaza(const std::vector <Activitate>& activitati) const;
};

