//
// Created by Alexander Winter on 2022-02-13.
//

#ifndef GAMETEMPLATE_FAKEASSET_H
#define GAMETEMPLATE_FAKEASSET_H


#include "WIZ/asset/Asset.h"

class FakeAsset : public wiz::Asset<void> {
	std::string name;
public:
	explicit FakeAsset(std::string name);

	void* load() const override;

	const std::string& getName() const override;

	void dispose(void* data) const override;
};


#endif //GAMETEMPLATE_FAKEASSET_H
