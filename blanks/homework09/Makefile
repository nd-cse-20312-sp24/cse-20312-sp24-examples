test:
	@$(MAKE) -sk test-all

test-all:	test-bst test-treap test-anagrams

test-bst: 	bst.py
	@echo Testing bst ...
	@chmod +x ./bst_test.py
	@./bst_test.py -v
	@echo

test-treap: 	treap.py
	@echo Testing treap ...
	@chmod +x ./treap_test.py
	@./treap_test.py -v
	@echo

test-anagrams: 	anagrams.py
	@echo Testing anagrams ...
	@chmod +x ./anagrams_test.py
	@./anagrams_test.py -v
	@echo

clean:
	@rm -fr __pycache__
