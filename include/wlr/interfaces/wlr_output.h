#ifndef WLR_INTERFACES_WLR_OUTPUT_H
#define WLR_INTERFACES_WLR_OUTPUT_H

#include <wlr/types/wlr_output.h>
#include <stdbool.h>

struct wlr_output_impl {
	void (*enable)(struct wlr_output *output, bool enable);
	bool (*set_mode)(struct wlr_output *output, struct wlr_output_mode *mode);
	void (*transform)(struct wlr_output *output,
			enum wl_output_transform transform);
	bool (*set_cursor)(struct wlr_output *output, const uint8_t *buf,
			int32_t stride, uint32_t width, uint32_t height,
			int32_t hotspot_x, int32_t hotspot_y);
	bool (*move_cursor)(struct wlr_output *output, int x, int y);
	void (*destroy)(struct wlr_output *output);
	void (*make_current)(struct wlr_output *output);
	void (*swap_buffers)(struct wlr_output *output);
	void (*set_gamma)(struct wlr_output *output,
			uint16_t size, uint16_t *r, uint16_t *g, uint16_t *b);
	uint16_t (*get_gamma_size)(struct wlr_output *output);
};

void wlr_output_init(struct wlr_output *output, const struct wlr_output_impl *impl);
void wlr_output_free(struct wlr_output *output);
void wlr_output_update_matrix(struct wlr_output *output);
struct wl_global *wlr_output_create_global(
		struct wlr_output *wlr_output, struct wl_display *display);

#endif
