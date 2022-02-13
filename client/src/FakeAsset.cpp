//
// Created by Alexander Winter on 2022-02-13.
//

#include <string>
#include <chrono>
#include <thread>
#include "FakeAsset.h"

void* FakeAsset::load() const {
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	return (void*)name.c_str();
}

const std::string& FakeAsset::getName() const {
	return name;
}

void FakeAsset::dispose(void* data) const {}

FakeAsset::FakeAsset(std::string name)
	: name(std::move(name)) {}
