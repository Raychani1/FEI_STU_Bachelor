function myMap() {
    const fei = {lat: 48.151891, lng: 17.073358};
    const directionsService = new google.maps.DirectionsService();
    const directionsRenderer = new google.maps.DirectionsRenderer();

    let mapProp = {
        center: fei,
        zoom: 18,
        streetViewControl: false,
    };
    let map = new google.maps.Map(document.getElementById("googleMap"), mapProp);

    const marker = new google.maps.Marker({
        position: fei,
        map: map,
        icon: {
            url: 'images/marker.png',
            labelOrigin: new google.maps.Point(18, 75),
        },
        label: {
            text: "FEI STU",
            color: "black",
            fontWeight: "bold",
        }
    })
    const contentString = "Latitude: 48.151891<br>Longitude: 17.073358";
    const infowindow = new google.maps.InfoWindow({
        content: contentString,
    });
    google.maps.event.addListener(marker, 'click', function () {
        infowindow.open(map, marker);
    });

    const panorama = new google.maps.StreetViewPanorama(
        document.getElementById("pano"),
        {
            position: fei,
            pov: {
                heading: 34,
                pitch: 10,
            }
        }
    );
    map.setStreetView(panorama);

    const input = document.getElementById("location");
    const searchBox = new google.maps.places.SearchBox(input);

    map.addListener("bounds_changed", () => {
        searchBox.setBounds(map.getBounds());
    });
    let markers = [];
    searchBox.addListener("places_changed", () => {
        const places = searchBox.getPlaces();

        if (places.length === 0) {
            return;
        }
        markers.forEach((marker) => {
            marker.setMap(null);
        });
        markers = [];
        const bounds = new google.maps.LatLngBounds();
        places.forEach((place) => {
            if (!place.geometry) {
                console.log("Returned place contains no geometry");
                return;
            }
            if (place.geometry.viewport) {
                // Only geocodes have viewport.
                bounds.union(place.geometry.viewport);
            } else {
                bounds.extend(place.geometry.location);
            }
        });
    });
    directionsRenderer.setMap(map);


    const eventHandler = function () {
        calculateAndDisplayRoute(directionsService, directionsRenderer);
    };

    document.getElementById("send").addEventListener("click", eventHandler);
    document.getElementById("travel").addEventListener("change", eventHandler);

    function getNearbyPlaces() {
        let request = {
            location: fei,
            radius: 300,
            keyword: "zastávka"
        };
        let service = new google.maps.places.PlacesService(map);
        service.nearbySearch(request, nearbyCallback);
        let request2 = {
            location: fei,
            radius: 300,
            keyword: 'tram'
        };
        service.nearbySearch(request2, nearbyCallback);
        let request3 = {
            location: fei,
            radius: 300,
            keyword: 'stop'
        };
        service.nearbySearch(request3, nearbyCallback);
        let request4 = {
            location: fei,
            radius: 300,
            keyword: 'Autobusová zastávka'
        };
        service.nearbySearch(request4, nearbyCallback);
        let request5 = {
            location: fei,
            radius: 300,
            keyword: 'bus'
        };
        service.nearbySearch(request5, nearbyCallback);

    }

    function nearbyCallback(results, status) {
        if (status === google.maps.places.PlacesServiceStatus.OK) {
            createMarkers(results);
        }
    }

    function createMarkers(places) {
        places.forEach(place => {
            let marker = new google.maps.Marker({
                position: place.geometry.location,
                map: map,
                title: place.name,
                icon: {
                    url: 'images/transit_stop.png',
                },
            });
        });
    }
    function public_transport_search(){
        map.setZoom(17);
        map.setCenter(fei);
        getNearbyPlaces();
    }
    document.getElementById("transit").addEventListener("click", public_transport_search);

}

function calculateAndDisplayRoute(directionsService, directionsRenderer) {
    const router = new google.maps.DirectionsService();
    router.route(
        {
            origin: {
                query: document.getElementById("location").value,
            },
            destination: {lat: 48.151891, lng: 17.073358},
            travelMode: $("input[name='travel']:radio:checked").val(),
            unitSystem: google.maps.UnitSystem.METRIC
        },
        (response, status) => {
            if (status === "OK") {
                directionsRenderer.setDirections(response);
                document.getElementById("distance_info").style.display = "block";
                document.getElementById("distance").innerHTML = response.routes[0].legs[0].distance.value / 1000;
            } else {
                window.alert("Directions request failed due to " + status);
            }
        }
    );
}
