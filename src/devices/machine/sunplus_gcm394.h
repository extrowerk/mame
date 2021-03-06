// license:BSD-3-Clause
// copyright-holders:David Haywood
/*****************************************************************************

  SunPlus "GCM394" (based on die pictures)

**********************************************************************/

#ifndef MAME_MACHINE_SUNPLUS_GCM394_H
#define MAME_MACHINE_SUNPLUS_GCM394_H

#pragma once

#include "cpu/unsp/unsp.h"
#include "screen.h"
#include "emupal.h"
#include "sunplus_gcm394_video.h"

class sunplus_gcm394_base_device : public device_t, public device_mixer_interface
{
public:
	sunplus_gcm394_base_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, type, tag, owner, clock)
	, device_mixer_interface(mconfig, *this, 2)
	, m_cpu(*this, finder_base::DUMMY_TAG)
	, m_screen(*this, finder_base::DUMMY_TAG)
	, m_palette(*this, "palette")
	, m_spg_video(*this, "spgvideo")
	{
	}

	void map(address_map &map);

	uint32_t screen_update(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect) { return m_spg_video->screen_update(screen, bitmap, cliprect); }

	DECLARE_WRITE_LINE_MEMBER(vblank) { m_spg_video->vblank(state); }

	virtual void device_add_mconfig(machine_config& config) override;

protected:

	virtual void device_start() override;
	virtual void device_reset() override;

	required_device<unsp_device> m_cpu;
	required_device<screen_device> m_screen;
	required_device<palette_device> m_palette;
	required_device<gcm394_video_device> m_spg_video;

	uint16_t m_dma_params[7];

	// unk 78xx
	uint16_t m_7803;

	uint16_t m_7807;

	uint16_t m_7810;

	uint16_t m_7816;
	uint16_t m_7817;


	uint16_t m_7819;

	uint16_t m_7820;
	uint16_t m_7821;
	uint16_t m_7822;
	uint16_t m_7823;
	uint16_t m_7824;

	uint16_t m_782d;

	uint16_t m_7835;

	uint16_t m_7860;

	uint16_t m_7861;

	uint16_t m_7862;
	uint16_t m_7863;

	uint16_t m_7870;

	uint16_t m_7871;

	uint16_t m_7872;
	uint16_t m_7873;

	uint16_t m_7882;
	uint16_t m_7883;

	uint16_t m_78a0;

	uint16_t m_78a4;
	uint16_t m_78a5;
	uint16_t m_78a6;

	uint16_t m_78a8;

	uint16_t m_78b0;
	uint16_t m_78b1;
	uint16_t m_78b2;

	uint16_t m_78b8;

	uint16_t m_78f0;

	uint16_t m_78fb;

	// unk 79xx
	uint16_t m_7934;
	uint16_t m_7936;


private:
	DECLARE_READ16_MEMBER(unk_r);
	DECLARE_WRITE16_MEMBER(unk_w);


	DECLARE_WRITE16_MEMBER(system_dma_params_w);
	DECLARE_WRITE16_MEMBER(system_dma_trigger_w);
	DECLARE_READ16_MEMBER(system_dma_status_r);

	DECLARE_READ16_MEMBER(unkarea_780f_status_r);
	DECLARE_READ16_MEMBER(unkarea_78fb_status_r);

	DECLARE_READ16_MEMBER(unkarea_7803_r);
	DECLARE_WRITE16_MEMBER(unkarea_7803_w);

	DECLARE_WRITE16_MEMBER(unkarea_7807_w);

	DECLARE_READ16_MEMBER(unkarea_7810_r);
	DECLARE_WRITE16_MEMBER(unkarea_7810_w);

	DECLARE_WRITE16_MEMBER(unkarea_7816_w);
	DECLARE_WRITE16_MEMBER(unkarea_7817_w);

	DECLARE_READ16_MEMBER(unkarea_7819_r);
	DECLARE_WRITE16_MEMBER(unkarea_7819_w);

	DECLARE_WRITE16_MEMBER(unkarea_7820_w);
	DECLARE_WRITE16_MEMBER(unkarea_7821_w);
	DECLARE_WRITE16_MEMBER(unkarea_7822_w);
	DECLARE_WRITE16_MEMBER(unkarea_7823_w);
	DECLARE_WRITE16_MEMBER(unkarea_7824_w);

	DECLARE_WRITE16_MEMBER(unkarea_7835_w);

	DECLARE_READ16_MEMBER(unkarea_7868_r);

	DECLARE_READ16_MEMBER(unkarea_782d_r);
	DECLARE_WRITE16_MEMBER(unkarea_782d_w);

	DECLARE_READ16_MEMBER(unkarea_7860_r);
	DECLARE_WRITE16_MEMBER(unkarea_7860_w);

	DECLARE_READ16_MEMBER(unkarea_7861_r);

	DECLARE_READ16_MEMBER(unkarea_7862_r);
	DECLARE_WRITE16_MEMBER(unkarea_7862_w);
	DECLARE_READ16_MEMBER(unkarea_7863_r);
	DECLARE_WRITE16_MEMBER(unkarea_7863_w);

	DECLARE_READ16_MEMBER(unkarea_7870_r);
	DECLARE_WRITE16_MEMBER(unkarea_7870_w);

	DECLARE_READ16_MEMBER(unkarea_7871_r);

	DECLARE_READ16_MEMBER(unkarea_7872_r);
	DECLARE_WRITE16_MEMBER(unkarea_7872_w);
	DECLARE_READ16_MEMBER(unkarea_7873_r);
	DECLARE_WRITE16_MEMBER(unkarea_7873_w);

	DECLARE_READ16_MEMBER(unkarea_7882_r);
	DECLARE_WRITE16_MEMBER(unkarea_7882_w);
	DECLARE_READ16_MEMBER(unkarea_7883_r);
	DECLARE_WRITE16_MEMBER(unkarea_7883_w);

	DECLARE_WRITE16_MEMBER(unkarea_78a0_w);

	DECLARE_WRITE16_MEMBER(unkarea_78a4_w);
	DECLARE_WRITE16_MEMBER(unkarea_78a5_w);
	DECLARE_WRITE16_MEMBER(unkarea_78a6_w);

	DECLARE_WRITE16_MEMBER(unkarea_78a8_w);

	DECLARE_WRITE16_MEMBER(unkarea_78b0_w);
	DECLARE_WRITE16_MEMBER(unkarea_78b1_w);
	DECLARE_WRITE16_MEMBER(unkarea_78b2_w);

	DECLARE_WRITE16_MEMBER(unkarea_78b8_w);

	DECLARE_WRITE16_MEMBER(unkarea_78f0_w);

	DECLARE_READ16_MEMBER(unkarea_7934_r);
	DECLARE_WRITE16_MEMBER(unkarea_7934_w);
	DECLARE_READ16_MEMBER(unkarea_7936_r);
	DECLARE_WRITE16_MEMBER(unkarea_7936_w);

	DECLARE_WRITE_LINE_MEMBER(videoirq_w);
};

class sunplus_gcm394_device : public sunplus_gcm394_base_device
{
public:
	template <typename T, typename U>
	sunplus_gcm394_device(const machine_config& mconfig, const char* tag, device_t* owner, uint32_t clock, T&& cpu_tag, U&& screen_tag)
		: sunplus_gcm394_device(mconfig, tag, owner, clock)
	{
		m_cpu.set_tag(std::forward<T>(cpu_tag));
		m_screen.set_tag(std::forward<U>(screen_tag));
	}

	sunplus_gcm394_device(const machine_config& mconfig, const char* tag, device_t* owner, uint32_t clock);
};


DECLARE_DEVICE_TYPE(GCM394, sunplus_gcm394_device)

#endif // MAME_MACHINE_SUNPLUS_GCM394_H
