test:
	@$(MAKE) -sk test-all

test-all:	test-flights test-sim-city test-passcode

test-flights: 	flights.py
	@echo Testing flights ...
	@chmod +x ./flights_test.py
	@./flights_test.py -v
	@echo

test-sim-city: 	sim_city.py
	@echo Testing sim_city ...
	@chmod +x ./sim_city_test.py
	@./sim_city_test.py -v
	@echo

test-passcode: 	passcode.py
	@echo Testing passcode ...
	@chmod +x ./passcode_test.py
	@./passcode_test.py -v
	@echo

clean:
	@rm -fr __pycache__
