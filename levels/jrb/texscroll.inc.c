void scroll_jrb_dl_Cube_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 138;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 1.0;
	float offsetX = 0.0;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Cube_mesh_layer_1_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;	timeX += 1;
}

void scroll_jrb() {
	scroll_jrb_dl_Cube_mesh_layer_1_vtx_0();
}
