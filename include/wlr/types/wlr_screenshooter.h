#ifndef _WLR_SCREENSHOOTER_H
#define _WLR_SCREENSHOOTER_H
#include <wayland-server.h>

struct wlr_screenshooter {
	struct wl_global *wl_global;
	struct wlr_renderer *renderer;

	void *data;
};

struct wlr_screenshot {
	struct wl_resource *resource;
	struct wl_resource *output_resource;

	struct wlr_output *output;
	struct wlr_screenshooter *screenshooter;

	void* data;
};

struct wlr_screenshooter *wlr_screenshooter_create(struct wl_display *display,
	struct wlr_renderer *renderer);
void wlr_screenshooter_destroy(struct wlr_screenshooter *screenshooter);

#endif
