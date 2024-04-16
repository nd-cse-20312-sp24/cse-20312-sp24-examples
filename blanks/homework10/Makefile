test:
	@$(MAKE) -sk test-all

test-all:	test-graph test-center-star test-reddit-groups

test-graph: 	graph.py
	@echo Testing graph ...
	@chmod +x ./graph_test.py
	@./graph_test.py -v
	@echo

test-center-star: 	center_star.py
	@echo Testing center_star ...
	@chmod +x ./center_star_test.py
	@./center_star_test.py -v
	@echo

test-reddit-groups: 	reddit_groups.py
	@echo Testing reddit_groups ...
	@chmod +x ./reddit_groups_test.py
	@./reddit_groups_test.py -v
	@echo

clean:
	@rm -fr __pycache__
