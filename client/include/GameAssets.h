//
// Created by Alexander Winter on 2022-02-13.
//

#ifndef GAMETEMPLATE_GAMEASSETS_H
#define GAMETEMPLATE_GAMEASSETS_H

#include "WIZ/asset/MusicAsset.h"
#include "WIZ/asset/SoundAsset.h"
#include "WIZ/asset/FontAsset.h"
#include "WIZ/asset/TextureAsset.h"
#include "FakeAsset.h"

#ifndef ASSET
#define ASSET(TYPE, NAME, CONSTRUCTOR) extern const TYPE NAME;
#endif

namespace GameAssets {
	extern std::vector<const wiz::AssetBase*> ALL;

	ASSET(wiz::MusicAsset, GREENLIFE, ("music/greenlife.ogg"))
	ASSET(wiz::SoundAsset, JUMP, ("sfx/jump.ogg"))
	ASSET(wiz::FontAsset, SANS_TTF, ("font/sans.ttf"))

	ASSET(wiz::TextureAsset, PLAYER, ("gfx/player.png"))
	ASSET(wiz::TextureAsset, BACKGROUND, ("gfx/background.jpg"))
	ASSET(wiz::TextureAsset, WHITE_PIXEL, ("gfx/white_pixel.png"))
	ASSET(wiz::TextureAsset, LOGO, ("gfx/logo.png"))

#ifdef SLOW
	ASSET(FakeAsset, FAKE_ASSET0, ("FakeAsset0"))
	ASSET(FakeAsset, FAKE_ASSET1, ("FakeAsset1"))
	ASSET(FakeAsset, FAKE_ASSET2, ("FakeAsset2"))
	ASSET(FakeAsset, FAKE_ASSET3, ("FakeAsset3"))
	ASSET(FakeAsset, FAKE_ASSET4, ("FakeAsset4"))
	ASSET(FakeAsset, FAKE_ASSET5, ("FakeAsset5"))
	ASSET(FakeAsset, FAKE_ASSET6, ("FakeAsset6"))
	ASSET(FakeAsset, FAKE_ASSET7, ("FakeAsset7"))
	ASSET(FakeAsset, FAKE_ASSET8, ("FakeAsset8"))
	ASSET(FakeAsset, FAKE_ASSET9, ("FakeAsset9"))

	ASSET(FakeAsset, FAKE_ASSET10, ("FakeAsset10"))
	ASSET(FakeAsset, FAKE_ASSET11, ("FakeAsset11"))
	ASSET(FakeAsset, FAKE_ASSET12, ("FakeAsset12"))
	ASSET(FakeAsset, FAKE_ASSET13, ("FakeAsset13"))
	ASSET(FakeAsset, FAKE_ASSET14, ("FakeAsset14"))
	ASSET(FakeAsset, FAKE_ASSET15, ("FakeAsset15"))
	ASSET(FakeAsset, FAKE_ASSET16, ("FakeAsset16"))
	ASSET(FakeAsset, FAKE_ASSET17, ("FakeAsset17"))
	ASSET(FakeAsset, FAKE_ASSET18, ("FakeAsset18"))
	ASSET(FakeAsset, FAKE_ASSET19, ("FakeAsset19"))

	ASSET(FakeAsset, FAKE_ASSET20, ("FakeAsset20"))
	ASSET(FakeAsset, FAKE_ASSET21, ("FakeAsset21"))
	ASSET(FakeAsset, FAKE_ASSET22, ("FakeAsset22"))
	ASSET(FakeAsset, FAKE_ASSET23, ("FakeAsset23"))
	ASSET(FakeAsset, FAKE_ASSET24, ("FakeAsset24"))
	ASSET(FakeAsset, FAKE_ASSET25, ("FakeAsset25"))
	ASSET(FakeAsset, FAKE_ASSET26, ("FakeAsset26"))
	ASSET(FakeAsset, FAKE_ASSET27, ("FakeAsset27"))
	ASSET(FakeAsset, FAKE_ASSET28, ("FakeAsset28"))
	ASSET(FakeAsset, FAKE_ASSET29, ("FakeAsset29"))

	ASSET(FakeAsset, FAKE_ASSET30, ("FakeAsset30"))
	ASSET(FakeAsset, FAKE_ASSET31, ("FakeAsset31"))
	ASSET(FakeAsset, FAKE_ASSET32, ("FakeAsset32"))
	ASSET(FakeAsset, FAKE_ASSET33, ("FakeAsset33"))
	ASSET(FakeAsset, FAKE_ASSET34, ("FakeAsset34"))
	ASSET(FakeAsset, FAKE_ASSET35, ("FakeAsset35"))
	ASSET(FakeAsset, FAKE_ASSET36, ("FakeAsset36"))
	ASSET(FakeAsset, FAKE_ASSET37, ("FakeAsset37"))
	ASSET(FakeAsset, FAKE_ASSET38, ("FakeAsset38"))
	ASSET(FakeAsset, FAKE_ASSET39, ("FakeAsset39"))

	ASSET(FakeAsset, FAKE_ASSET40, ("FakeAsset40"))
	ASSET(FakeAsset, FAKE_ASSET41, ("FakeAsset41"))
	ASSET(FakeAsset, FAKE_ASSET42, ("FakeAsset42"))
	ASSET(FakeAsset, FAKE_ASSET43, ("FakeAsset43"))
	ASSET(FakeAsset, FAKE_ASSET44, ("FakeAsset44"))
	ASSET(FakeAsset, FAKE_ASSET45, ("FakeAsset45"))
	ASSET(FakeAsset, FAKE_ASSET46, ("FakeAsset46"))
	ASSET(FakeAsset, FAKE_ASSET47, ("FakeAsset47"))
	ASSET(FakeAsset, FAKE_ASSET48, ("FakeAsset48"))
	ASSET(FakeAsset, FAKE_ASSET49, ("FakeAsset49"))

	ASSET(FakeAsset, FAKE_ASSET50, ("FakeAsset50"))
	ASSET(FakeAsset, FAKE_ASSET51, ("FakeAsset51"))
	ASSET(FakeAsset, FAKE_ASSET52, ("FakeAsset52"))
	ASSET(FakeAsset, FAKE_ASSET53, ("FakeAsset53"))
	ASSET(FakeAsset, FAKE_ASSET54, ("FakeAsset54"))
	ASSET(FakeAsset, FAKE_ASSET55, ("FakeAsset55"))
	ASSET(FakeAsset, FAKE_ASSET56, ("FakeAsset56"))
	ASSET(FakeAsset, FAKE_ASSET57, ("FakeAsset57"))
	ASSET(FakeAsset, FAKE_ASSET58, ("FakeAsset58"))
	ASSET(FakeAsset, FAKE_ASSET59, ("FakeAsset59"))

	ASSET(FakeAsset, FAKE_ASSET60, ("FakeAsset60"))
	ASSET(FakeAsset, FAKE_ASSET61, ("FakeAsset61"))
	ASSET(FakeAsset, FAKE_ASSET62, ("FakeAsset62"))
	ASSET(FakeAsset, FAKE_ASSET63, ("FakeAsset63"))
	ASSET(FakeAsset, FAKE_ASSET64, ("FakeAsset64"))
	ASSET(FakeAsset, FAKE_ASSET65, ("FakeAsset65"))
	ASSET(FakeAsset, FAKE_ASSET66, ("FakeAsset66"))
	ASSET(FakeAsset, FAKE_ASSET67, ("FakeAsset67"))
	ASSET(FakeAsset, FAKE_ASSET68, ("FakeAsset68"))
	ASSET(FakeAsset, FAKE_ASSET69, ("FakeAsset69"))

	ASSET(FakeAsset, FAKE_ASSET70, ("FakeAsset70"))
	ASSET(FakeAsset, FAKE_ASSET71, ("FakeAsset71"))
	ASSET(FakeAsset, FAKE_ASSET72, ("FakeAsset72"))
	ASSET(FakeAsset, FAKE_ASSET73, ("FakeAsset73"))
	ASSET(FakeAsset, FAKE_ASSET74, ("FakeAsset74"))
	ASSET(FakeAsset, FAKE_ASSET75, ("FakeAsset75"))
	ASSET(FakeAsset, FAKE_ASSET76, ("FakeAsset76"))
	ASSET(FakeAsset, FAKE_ASSET77, ("FakeAsset77"))
	ASSET(FakeAsset, FAKE_ASSET78, ("FakeAsset78"))
	ASSET(FakeAsset, FAKE_ASSET79, ("FakeAsset79"))

	ASSET(FakeAsset, FAKE_ASSET80, ("FakeAsset80"))
	ASSET(FakeAsset, FAKE_ASSET81, ("FakeAsset81"))
	ASSET(FakeAsset, FAKE_ASSET82, ("FakeAsset82"))
	ASSET(FakeAsset, FAKE_ASSET83, ("FakeAsset83"))
	ASSET(FakeAsset, FAKE_ASSET84, ("FakeAsset84"))
	ASSET(FakeAsset, FAKE_ASSET85, ("FakeAsset85"))
	ASSET(FakeAsset, FAKE_ASSET86, ("FakeAsset86"))
	ASSET(FakeAsset, FAKE_ASSET87, ("FakeAsset87"))
	ASSET(FakeAsset, FAKE_ASSET88, ("FakeAsset88"))
	ASSET(FakeAsset, FAKE_ASSET89, ("FakeAsset89"))

	ASSET(FakeAsset, FAKE_ASSET90, ("FakeAsset90"))
	ASSET(FakeAsset, FAKE_ASSET91, ("FakeAsset91"))
	ASSET(FakeAsset, FAKE_ASSET92, ("FakeAsset92"))
	ASSET(FakeAsset, FAKE_ASSET93, ("FakeAsset93"))
	ASSET(FakeAsset, FAKE_ASSET94, ("FakeAsset94"))
	ASSET(FakeAsset, FAKE_ASSET95, ("FakeAsset95"))
	ASSET(FakeAsset, FAKE_ASSET96, ("FakeAsset96"))
	ASSET(FakeAsset, FAKE_ASSET97, ("FakeAsset97"))
	ASSET(FakeAsset, FAKE_ASSET98, ("FakeAsset98"))
	ASSET(FakeAsset, FAKE_ASSET99, ("FakeAsset99"))
#endif
}


#endif //GAMETEMPLATE_GAMEASSETS_H
