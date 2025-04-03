package com.example.adl10;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.bumptech.glide.Glide;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.Random;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class MainActivity extends AppCompatActivity {
    private ImageView wallpaperView;
    private Button nextButton, downloadButton;
    private ProgressBar progressBar;
    private String currentWallpaperUrl = "";

    private static final String BASE_URL = "http://100.114.252.62:5080/wallpapers";

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        wallpaperView = findViewById(R.id.wallpaperView);
        nextButton = findViewById(R.id.nextButton);
        downloadButton = findViewById(R.id.downloadButton);
        progressBar = findViewById(R.id.progressBar);

        fetchWallpaper();

        nextButton.setOnClickListener(v -> fetchWallpaper());
        downloadButton.setOnClickListener(v -> downloadWallpaper());
    }

    private void fetchWallpaper() {
        progressBar.setVisibility(View.VISIBLE);
        OkHttpClient client = new OkHttpClient();

        Request request = new Request.Builder().url(BASE_URL).build();
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                runOnUiThread(() -> {
                    progressBar.setVisibility(View.GONE);
                    Toast.makeText(MainActivity.this, "Failed to load wallpapers", Toast.LENGTH_SHORT).show();
                });
            }

            @Override
            public void onResponse(Call call, Response response) throws IOException {
                if (response.isSuccessful() && response.body() != null) {
                    try {
                        JSONArray wallpapers = new JSONArray(response.body().string());
                        if (wallpapers.length() > 0) {
                            JSONObject wallpaper = wallpapers.getJSONObject(new Random().nextInt(wallpapers.length()));
                            currentWallpaperUrl = wallpaper.getString("url");
                            runOnUiThread(() -> {
                                Glide.with(MainActivity.this).load(currentWallpaperUrl).into(wallpaperView);
                                progressBar.setVisibility(View.GONE);
                            });
                        }
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
            }
        });
    }

    private void downloadWallpaper() {
        if (!currentWallpaperUrl.isEmpty()) {
            Toast.makeText(this, "Downloading: " + currentWallpaperUrl, Toast.LENGTH_SHORT).show();
            // Implement wallpaper downloading logic here
        } else {
            Toast.makeText(this, "No wallpaper to download", Toast.LENGTH_SHORT).show();
        }
    }
}
