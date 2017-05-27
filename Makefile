.PHONY: clean All

All:
	@echo "----------Building project:[ PencilSim - Debug ]----------"
	@cd "PencilSim" && "$(MAKE)" -f  "PencilSim.mk"
clean:
	@echo "----------Cleaning project:[ PencilSim - Debug ]----------"
	@cd "PencilSim" && "$(MAKE)" -f  "PencilSim.mk" clean
