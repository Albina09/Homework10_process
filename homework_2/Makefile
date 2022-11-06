.PHONY := clean
object = child Project
all: $(object)

$(object): %: %.c  
		gcc $< -o $@


.PHONY := clean
clean:
		rm -rf $(object)

